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
for (i = 0; i <= 255; i++) {
    if (Red >= 0) {
        histogram[Red][i] = 0;
    }
    if (Green >= 0) {
        histogram[Green][i] = 0;
    }
    if (Blue >= 0) {
        histogram[Blue][i] = 0;
    }
}
}
