#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int Blue;
extern  int Green;
extern  int Red;
extern ssize_t **histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t temp_red, temp_green, temp_blue;
    for (i = 0; i <= 255; i++) {
        temp_red = 0;
        temp_green = 0;
        temp_blue = 0;
        histogram[Red][i] = temp_red;
        histogram[Green][i] = temp_green;
        histogram[Blue][i] = temp_blue;
    }
}
