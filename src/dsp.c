#include <raylib.h>
#include<stdio.h>
#include <string.h>
#include "debug_tools.h"
#include "main_menu.h"
#include"vector_math.h"
#include"stdlib.h"
#include<complex.h>
#include<math.h>

//Prints out a waves sample
void print_wave(Wave wave){

    //Load the samples of the wave
    float *wave_samples = LoadWaveSamples(wave);

    //Iterate through each frame in the wave
    for(int i = 0; i < wave.frameCount; i++){
        printf("Frame %d: %f\n", i, *(wave_samples + i));
    }

}



//Draws all the points of a wave 
void draw_twave(Wave wave, Vector2 start_point, MainMenu *menu){

    if(menu->wave_points_calced == 0){

        float *wave_samples = LoadWaveSamples(wave);

        Vector2 vec_array[wave.frameCount];

        vec_array[0] = start_point;

        Vector2 curr_vec;

        for(int i = 1; i < wave.frameCount; i++){

            //Fit waveform to window
            
            //Check pixel per frame is correct
            //printf("Pixels per frame: %f\n", (float) menu.screenWidth/wave.frameCount);

            curr_vec.x = start_point.x + (i*((double) menu->screenWidth/ (double) wave.frameCount));
            curr_vec.y = (start_point.y + (*(wave_samples + i) * 250));



            vec_array[i] = curr_vec;
        }

        memcpy(menu->wave_points, vec_array, sizeof(vec_array));
        menu->wave_points_calced = 1;

    }

    
    DrawLineStrip(menu->wave_points, wave.frameCount, BLACK);

}



//FFT algorithm 
//Adapted from the psuedocode at: https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm
//x is the input array, N is the number of samples ,s is the stride of the input array
//Sort of like a divide and conquer method
float *cooley_tukey(float *x, int N ,int s){   
    
      float *comb_dft = malloc(N * sizeof(float));

    //Trivial 1 frame DFT
    if(N==1){
        return x;
    }
      

    float *a_dft = malloc(N/2 * sizeof(float));
    float *b_dft = malloc(N/2 * sizeof(float));


    //Split the float array in half - recursive
    for(int k = 0; k <N/2; k++){
        a_dft[k] = x[2*k];
        b_dft[k] = x[2*k +1];
    }


    float *A_dft = cooley_tukey(a_dft, N/2, 2*s);
    float *B_dft  = cooley_tukey(b_dft, N/2, 2*s);

    free(a_dft);
    free(b_dft);

    //Combine the DFTs into full DFT
    for(int k = 0; k < N/2 - 1; k++){
        //Access the float at space k in the "array"
        float p = *(A_dft + k);
        
        //Exponential of (-2pi*(i) divided by N all multiplied by k) multiplied by the relevant dfted frame. 
        float q = exp(((-2 * PI * I)/N) * k) * *(B_dft + k);
        
        comb_dft[k] = p + q;
        
        comb_dft[k + N/2] = p - q;
    }          


    
    return comb_dft;   


}




void draw_fwave(Wave wave, Vector2 start_point, MainMenu *menu){


    if(menu->wave_points_calced == 0){


        float *wave_samples = LoadWaveSamples(wave);   
        
        float *fft_wave = malloc(wave.frameCount * sizeof(float));

        //Make sure that the number of frames is an equal number
        if(wave.frameCount % 2 != 0){       

            //If an odd number, ignore the last frame
            fft_wave = cooley_tukey(wave_samples, wave.frameCount - 1, 1);
                   
        }
        else{
            fft_wave = cooley_tukey(wave_samples, wave.frameCount, 1);
        }

        Vector2 vec_array[wave.frameCount];

        vec_array[0] = start_point;

        Vector2 curr_vec;

        for(int i = 1; i < wave.frameCount; i++){

            //Fit waveform to window
            curr_vec.x = start_point.x + (i*((double) menu->screenWidth/ (double) wave.frameCount));
            curr_vec.y = (start_point.y + (*(fft_wave + i)));

            
            vec_array[i] = curr_vec;
        }

        free(fft_wave);


        //log_points(vec_array, sizeof(vec_array));

        memcpy(menu->wave_points, vec_array, sizeof(vec_array));
        menu->wave_points_calced = 1;   

    
    }

    //printf("Wave count: %d", wave.frameCount);

    
    
    DrawLineStrip(menu->wave_points, wave.frameCount, BLACK);  
}










