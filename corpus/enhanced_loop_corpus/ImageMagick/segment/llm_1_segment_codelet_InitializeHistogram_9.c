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
    for (i = 0; i <= 255; i += 4) {
        ssize_t j = i;
        histogram[Red][j] = 0;
        histogram[Green][j] = 0;
        histogram[Blue][j] = 0;
        if (j + 1 <= 255) {
            histogram[Red][j+1] = 0;
            histogram[Green][j+1] = 0;
            histogram[Blue][j+1] = 0;
        }
        if (j + 2 <= 255) {
            histogram[Red][j+2] = 0;
            histogram[Green][j+2] = 0;
            histogram[Blue][j+2] = 0;
        }
        if (j + 3 <= 255) {
            histogram[Red][j+3] = 0;
            histogram[Green][j+3] = 0;
            histogram[Blue][j+3] = 0;
        }
    }
}
