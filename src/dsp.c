#include <raylib.h>
#include<stdio.h>
#include <string.h>
#include "main_menu.h"
#include"vector_math.h"
#include"stdlib.h"


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
void draw_twave(Wave wave, Vector2 start_point, MainMenu menu){

//TODO: Figure out how to normalise wave so that it fits the full screen. (otherwise only certian length waves will fit)

    float *wave_samples = LoadWaveSamples(wave);

    Vector2 vec_array[wave.frameCount];

    vec_array[0] = start_point;

    Vector2 curr_vec;

    for(int i = 1; i < wave.frameCount; i++){

        //Fit waveform to window
        
        //Check pixel per frame is correct
        //printf("Pixels per frame: %f\n", (float) menu.screenWidth/wave.frameCount);

        curr_vec.x = start_point.x + (i*((double) menu.screenWidth/ (double) wave.frameCount));
        curr_vec.y = (start_point.y + (*(wave_samples + i) * 250));



        vec_array[i] = curr_vec;
    }

    DrawLineStrip(vec_array, wave.frameCount, BLACK);

}


void draw_fwave(Wave wave, Vector2 start_point, MainMenu menu){

    float *wave_samples = LoadWaveSamples(wave);




}











