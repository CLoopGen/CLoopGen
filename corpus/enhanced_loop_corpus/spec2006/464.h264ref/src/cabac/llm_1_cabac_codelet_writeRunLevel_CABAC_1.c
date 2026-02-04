#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = pos; outer < 64; outer += 32) {
        for (int inner = outer; inner < outer + 32 && inner < 64; inner++) {
            coeff[inner] = 0;
            pos = inner + 1;
        }
    }
}
