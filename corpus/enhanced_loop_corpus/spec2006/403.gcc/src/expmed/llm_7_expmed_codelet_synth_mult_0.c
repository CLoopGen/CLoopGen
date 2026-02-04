#include <stdio.h>

#include <inttypes.h>

extern unsigned long t;
extern unsigned long w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long flag = (w & t) != 0;
    for (unsigned long iter = 1; flag; iter <<= 1){
        w = iter; // Eliminate direct loop-carried dependency on 'w' by using 'iter'; breaks RAW on 'w'
        flag = (w & t) != 0;
    }
}
