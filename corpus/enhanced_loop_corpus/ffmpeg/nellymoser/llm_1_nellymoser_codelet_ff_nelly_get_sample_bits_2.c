#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i;
    for (temp_i = i; temp_i < 124; temp_i++) {
        bits[temp_i] = 0;
    }
    i = temp_i;
}
