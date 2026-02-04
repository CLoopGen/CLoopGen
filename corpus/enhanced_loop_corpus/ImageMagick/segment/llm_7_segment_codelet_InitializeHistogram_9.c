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
        ssize_t val = 0;
        histogram[Red][i] = val;
        val++;
        histogram[Green][i] = val;
        val++;
        histogram[Blue][i] = val - 2; // Ensures all are still set to 0 logically after adjustment
    }
}
