#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[100];
    for (i = 0; i < 100; i++) {
        temp[i] = i;
    }
    for (i = 0; i < 100; i++) {
        J[i] = temp[i];
    }
}
