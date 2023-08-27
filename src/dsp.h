#ifndef DSP_H
#define DSP_H

#include <raylib.h>
#include<stdio.h>
#include "main_menu.h"
#include"vector_math.h"

//Toolset to help manipulate raylibs Wave Struct

//Prints out a waves samples 
void print_wave(Wave wave);

//Draws a given wave in the time domain
//Starts at the given point, assuming that is 0,0 of the wave
void draw_twave(Wave wave, Vector2 start_point, MainMenu menu);

void draw_fwave(Wave wave, Vector2 start_point, MainMenu menu);


#endif