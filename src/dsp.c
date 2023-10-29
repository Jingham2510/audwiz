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
    
    //Trivial 1 frame DFT
    if(N==1){
        return x;
    }
    else{      

        //Split the float array in half - recursive
        float *a_dft = cooley_tukey(x, N/2, 2*s);
        float *b_dft = cooley_tukey((x+s), N/2, 2*s);

        //Combine the DFTs into full DFT
        for(int k = 0; k < N/2 - 1; k++){
            //Access the float at space k in the "array"
            float p = *(a_dft + k);
            
            //Exponential of (-2pi*(i) divided by N all multiplied by k) multiplied by the relevant dfted frame. 
            float q = exp(((-2 * PI * I)/N) * k) * *(b_dft + k);
            
            *(a_dft + k) = p + q;
            
            *(b_dft + k) = p - q;           

        }

        //Combine the DFT arrays into one DFT
        float *comb_dft = malloc(N * sizeof(float));

        int a_cnt = 0;
        int b_cnt = 0;

        //Interlace the two arrays with one-another
        for(int i = 0; i < N; i++){

            if(i % 2 == 0){
                *(comb_dft + i) = *(a_dft + a_cnt);
                a_cnt++;
            }
            else{
                *(comb_dft + i) = *(b_dft + b_cnt);
                b_cnt++;
            }
        }

        /*
        //OLD VERSION OF COMBINATION - Doesnt put them in alternating order, just one after the other
        memcpy(comb_dft, a_dft, N/2 * sizeof(float));
        memcpy(comb_dft + N/2, b_dft, N/2 * sizeof(float));
        */
        





        return comb_dft;

    }


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

        
        log_points(vec_array, sizeof(vec_array));

        memcpy(menu->wave_points, vec_array, sizeof(vec_array));
        menu->wave_points_calced = 1;   

    
    }

    //printf("Wave count: %d", wave.frameCount);

    
    
    DrawLineStrip(menu->wave_points, wave.frameCount, BLACK);  
}










