#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 50; i++) {
        J[2*i] = i * 20;
        J[2*i + 1] = (i + 1) * 20;
    }
}
