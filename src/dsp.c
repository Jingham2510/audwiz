#include <raylib.h>
#include<stdio.h>
#include"vector_math.h"


//Prints out a waves sample
void print_wave(Wave wave){

    //Load the samples of the wave
    float *wave_samples = LoadWaveSamples(wave);

    //Iterate through each frame in the wave
    for(int i = 0; i < wave.frameCount; i++){
        printf("Frame %d: %f\n", i, *(wave_samples + i));
    }

}




void draw_wave(Wave wave, Vector2 start_point){





}











