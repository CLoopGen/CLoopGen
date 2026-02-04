#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 4; i++) {
        int offset = (iy * 2) + (i % 4);
        ((float *)Y)[offset] = 0.0f;
        if ((i % 4) == 3) {
            iy += incY;
        }
    }
}
