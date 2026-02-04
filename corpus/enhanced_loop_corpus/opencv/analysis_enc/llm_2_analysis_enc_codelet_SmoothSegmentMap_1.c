#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int w;
extern  int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using step size > 1
    // Here we simulate strided iteration by incrementing x and y in steps of 2
    for (y = 1; y < h - 1; y += 2) {
        for (x = 1; x < w - 1; x += 2) {
        }
    }
}
