#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int tenl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int stride = 2;
    int temp = 1;
    for (j = 0; j < (length - 1) * stride; j += stride) {
        temp *= 10;
    }
    tenl = temp;
}
