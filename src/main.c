#include "raylib.h"
#include "main_menu.h"
#include "menu_tools.h"
#include <stdio.h>


//CURRENT COMPILE COMMAND : gcc main.c main_menu.c point.c -o main.exe -lraylib -lm

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "AUD_WIZ");

    SetTargetFPS(60);               // Set the app to run at 60 frames-per-second
      //Determining default menu
    enum menus curr_menu = MAIN;

    // SETUP MAIN MENU STRUCT
    MainMenu mainmenu;
    InitMainMenu(&mainmenu, screenWidth, screenHeight);

    //
    //Initialise Audio Device
    InitAudioDevice();

    Wave curr_wave = LoadWave("sounds/spell.wav");
    Sound curr_sound = LoadSoundFromWave(curr_wave);

    

    //--------------------------------------------------------------------------------------

  

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        //Check to see if there has been a click
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            switch(curr_menu){
                case MAIN:
                    MainMenuCheck(&mainmenu);
                    break;
                default:
                    break;
            }
        } 

        //Check which waveform to load
        if(mainmenu.play_music){            
            
            if(IsAudioDeviceReady()){
                printf("DEVICE READY\n");
                PlaySound(curr_sound);
                mainmenu.play_music = 0;
            }

        } 
        

        
        




        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(curr_menu) {
                case MAIN:
                    DrawMainMenu(&mainmenu);
                    break;

                default:
                    DrawMainMenu(&mainmenu);
                    break;
            }
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}