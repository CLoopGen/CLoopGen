#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= ((255 + 1) / 16); stride *= 2) {
        for (in = 0; in < stride && in < ((255 + 1) / 16); in++ , out++) {
            table[in] = out;
            table[-in] = -out;
        }
    }
}
