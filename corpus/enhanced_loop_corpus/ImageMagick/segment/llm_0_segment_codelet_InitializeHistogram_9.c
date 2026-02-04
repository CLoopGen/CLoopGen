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
        for (ssize_t channel = 0; channel < 3; channel++) {
            if (channel == 0)
                histogram[Red][i] = 0;
            else if (channel == 1)
                histogram[Green][i] = 0;
            else if (channel == 2)
                histogram[Blue][i] = 0;
        }
    }
}
