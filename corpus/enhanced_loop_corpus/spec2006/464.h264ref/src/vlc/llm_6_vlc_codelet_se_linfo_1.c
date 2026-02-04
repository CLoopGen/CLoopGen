#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = nn;
    for (i = 0; i < 16 && temp != 0; i++) {
        temp /= 2;
        nn = temp; // Introduce WAW dependency: write-after-write on 'nn'
    }
}
