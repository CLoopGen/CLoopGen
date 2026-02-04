#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[124];
    for (int j = 0; j < 124; j++) {
        indices[j] = 123 - j; // reverse access pattern
    }
    for (i = 0; i < 124; i++) {
        int idx = indices[i];
        max = ((max) > (buf[idx]) ? (max) : (buf[idx]));
    }
}
