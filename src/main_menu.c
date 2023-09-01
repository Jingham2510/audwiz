#include "main_menu.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>




void DrawTimeButton(MainMenu *menu){
    //Draws Load WAV button
    
    
    menu->LOAD_BUTTON_SIZE = 50;
    
    DrawCircleLines(menu->time_button_cntr.x, menu->time_button_cntr.y, menu->LOAD_BUTTON_SIZE, BLACK);
    const char* time_text = "TIME";
    int load_font_size = menu->LOAD_BUTTON_SIZE/2;
    int load_text_length = MeasureText(time_text, load_font_size);
    DrawText(time_text, menu->time_button_cntr.x - load_text_length/2.0f, menu->time_button_cntr.y - load_font_size/2.0f, load_font_size, BLACK);


}

void DrawFreqButton(MainMenu *menu){

    DrawCircleLines(menu->freq_button_cntr.x, menu->freq_button_cntr.y, menu->LOAD_BUTTON_SIZE, BLACK);
    const char* freq_text = "FREQ";
    int load_font_size = menu->LOAD_BUTTON_SIZE/2;
    int load_text_length = MeasureText(freq_text, load_font_size);
    DrawText(freq_text, menu->freq_button_cntr.x - load_text_length/2.0f, menu->freq_button_cntr.y - load_font_size/2.0f, load_font_size, BLACK);



}

void InitMainMenu(MainMenu *menu, int screenWidth, int screenHeight){

    //Store the screen width/height
    menu->screenWidth = screenWidth;
    menu->screenHeight = screenHeight;
    //Determine where the buttons should be drawn
    menu->time_button_cntr.x = menu->screenWidth * 0.75f;
    menu->time_button_cntr.y = menu->screenHeight *0.10f;

    menu->freq_button_cntr.x = menu->screenWidth * 0.90f;
    menu->freq_button_cntr.y = menu->screenHeight *0.10f;
    

    menu->play_music = 0;
    menu->display_wave = 0;
    menu->wave_points_calced = 0;
    
    menu->wave_points = malloc(100000 * sizeof(Vector2));


}


//Draws all the button shapes on the main menu
void DrawMainMenu(MainMenu *menu){

      
    DrawTimeButton(menu);
    DrawFreqButton(menu);   
}

//Checks where a left click is on the main menu
void MainMenuCheck(MainMenu *menu){
   
    
    //Get the mouse positive
    Vector2 mouse_pos = GetMousePosition();
    //Conversion from Vector 2 to my pnt type 

    
    //LOAD BUTTON CHECK
    if(PointDistance(mouse_pos, menu->time_button_cntr) < menu->LOAD_BUTTON_SIZE){
        
        
        menu->play_music = 1; 
        menu->display_wave = 1;
        menu->wave_m = TIME_MODE;
        menu->wave_points_calced = 0;
        
        free(menu->wave_points);
        menu->wave_points = malloc(100000 * sizeof(Vector2));
   }

    else if(PointDistance(mouse_pos, menu->freq_button_cntr) < menu->LOAD_BUTTON_SIZE){
            
        menu->play_music = 1; 
        menu->display_wave = 1;
        menu->wave_m = FREQ_MODE;    
        menu->wave_points_calced = 0;
        
        free(menu->wave_points);
        menu->wave_points = malloc(100000 * sizeof(Vector2));    
    }

    else{
        menu->play_music = 0;
        menu->display_wave = 0;        
    }
}


