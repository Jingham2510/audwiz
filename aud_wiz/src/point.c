#include "point.h"
#include<stdlib.h>
#include <math.h>


//Calculate distances between two points 
int PointDistance( pnt point1, pnt point2){
    int x_dist = abs(point1.x - point2.x);
    int y_dist = abs(point1.y - point2.y);

    
    int dist = sqrt(pow(x_dist, 2) + pow(y_dist, 2));

    

    return dist;
}

