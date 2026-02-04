#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double white_point;
extern double *histogram;
extern double intensity;
extern ssize_t white;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (white = (ssize_t)65535UL; white > 32767; white--) {
    intensity += histogram[white];
    if (intensity >= white_point)
        break;
}
for (; white != 0; white--) {
    intensity += histogram[white];
    if (intensity >= white_point)
        break;
}
}
