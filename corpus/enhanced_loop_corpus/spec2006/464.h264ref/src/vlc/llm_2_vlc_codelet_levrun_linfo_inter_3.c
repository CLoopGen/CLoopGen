#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *ptr = &nn;
    for (i = 0; i < 16 && *(ptr) != 0; i++) {
        *(ptr) /= 2;
    }
}
