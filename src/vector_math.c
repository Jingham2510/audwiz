#include "vector_math.h"
#include<stdlib.h>
#include <math.h>


//Calculate distances between two points 
int PointDistance( Vector2 point1, Vector2 point2){
    int x_dist = fabsf(point1.x - point2.x);
    int y_dist = fabsf(point1.y - point2.y);

    
    int dist = sqrt(pow(x_dist, 2) + pow(y_dist, 2));

    

    return dist;
}

