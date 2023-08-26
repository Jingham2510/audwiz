#include "main_menu.h"
#include <raylib.h>
#include <stdio.h>




void DrawLoadButton(MainMenu *menu){
    //Draws Load WAV button
    
    
    menu->LOAD_BUTTON_SIZE = 50;

    int LOAD_BUTTON_SIZE = 50;
    DrawCircleLines(menu->load_button_cntr.x, menu->load_button_cntr.y, menu->LOAD_BUTTON_SIZE, BLACK);
    const char* load_text = "LOAD";
    int load_font_size = menu->LOAD_BUTTON_SIZE/2;
    int load_text_length = MeasureText(load_text, load_font_size);
    DrawText(load_text, menu->load_button_cntr.x - load_text_length/2.0f, menu->load_button_cntr.y - load_font_size/2.0f, load_font_size, BLACK);


}

void InitMainMenu(MainMenu *menu, int screenWidth, int screenHeight){

    //Store the screen width/height
    menu->screenWidth = screenWidth;
    menu->screenHeight = screenHeight;
    //Determine where the buttons should be drawn
    menu->load_button_cntr.x = menu->screenWidth * 0.90f;
    menu->load_button_cntr.y = menu->screenHeight *0.10f;

    menu->play_music = 0;

    



}


//Draws all the button shapes on the main menu
void DrawMainMenu(MainMenu *menu){

      
    DrawLoadButton(menu);
   
}

//Checks where a left click is on the main menu
void MainMenuCheck(MainMenu *menu){
   
    
    //Get the mouse positive
    Vector2 mouse_pos = GetMousePosition();
    //Conversion from Vector 2 to my pnt type 

    
    //LOAD BUTTON CHECK
    if(PointDistance(mouse_pos, menu->load_button_cntr) < menu->LOAD_BUTTON_SIZE){
        
        menu->play_music = 1;           

    }

    else{
        menu->play_music = 0;        
    }
        

    



    



}


