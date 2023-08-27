#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "raylib.h"
#include "vector_math.h"

enum wave_mode{

    TIME_MODE = 0,
    FREQ_MODE = 1
};

typedef struct{

    int screenWidth;
    int screenHeight;

    Vector2 time_button_cntr;
    Vector2 freq_button_cntr;
    int LOAD_BUTTON_SIZE;    

    bool play_music;
    bool display_wave;

    enum wave_mode wave_m;


} MainMenu;




//Initialises all the main menu variables
void InitMainMenu(MainMenu *menu,  int screenWidth, int screenHeight);

//Draws the main menu
void DrawMainMenu(MainMenu *menu);

//Checks for interaction on the main menu
void MainMenuCheck(MainMenu *menu);



#endif