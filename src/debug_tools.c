#include "debug_tools.h"
#include <stdio.h>



//Streams a set of wave points to a log file
void log_points(Vector2 * wave_points, int point_arr_len){

//Declare a new text file (title based on the date)
FILE *fptr;



//Open the text file
fptr = fopen("src/log/points_log.txt", "w");


//Iterate through the points and place them in the file
for(int i = 0; i < point_arr_len; i++){

    printf("X: %f  Y: %f \n", (wave_points + i)->x, (wave_points+i)->y);



    fprintf(fptr, "X: %f  Y: %f \n", (wave_points + i)->x, (wave_points+i)->y);

}


//Save and Close the file
fclose(fptr);


}