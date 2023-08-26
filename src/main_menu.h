#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "raylib.h"
#include "vector_math.h"
typedef struct{

    int screenWidth;
    int screenHeight;

    Vector2 load_button_cntr;
    int LOAD_BUTTON_SIZE;    

    bool play_music;


} MainMenu;

//Initialises all the main menu variables
void InitMainMenu(MainMenu *menu,  int screenWidth, int screenHeight);

//Draws the main menu
void DrawMainMenu(MainMenu *menu);

//Checks for interaction on the main menu
void MainMenuCheck(MainMenu *menu);



#endif