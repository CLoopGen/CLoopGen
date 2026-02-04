#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = &nn;
    for (i = 0; i < 16 && array[0] != 0; i++) {
        array[0] /= 2;
    }
}
