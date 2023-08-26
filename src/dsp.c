#include <raylib.h>
#include<stdio.h>
#include <string.h>
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
void draw_wave(Wave wave, Vector2 start_point){

//TODO: Determine Starting Point X and Y 
//Go through each point and determine where to draw it 
//i.e. create a vector array by going through each frame and turning it into a vector

    float *wave_samples = LoadWaveSamples(wave);


    /* MALLOC VERSION
    
    Vector2 *vec_array = malloc(wave.frameCount * sizeof(float));

    printf("memory initialised");

    memcpy(vec_array, &start_point, sizeof(Vector2));

    printf("First point loaded/n");

    Vector2 curr_vec;

    for(int i =1; i < wave.frameCount; i++){
        
        curr_vec.x = start_point.x + i;
        curr_vec.y = start_point.y + *(wave_samples + i);

        memcpy((vec_array + i*sizeof(Vector2)), &curr_vec, sizeof(Vector2));
    }

    */


    Vector2 vec_array[wave.frameCount];

    vec_array[0] = start_point;

    Vector2 curr_vec;

    for(int i =1; i < wave.frameCount; i++){
        
        curr_vec.x = start_point.x + i/80.0f;
        curr_vec.y = (start_point.y + (*(wave_samples + i) * 250));



        vec_array[i] = curr_vec;
    }

    DrawLineStrip(vec_array, wave.frameCount, BLACK);

}











