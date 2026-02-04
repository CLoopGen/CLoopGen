#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; pos < 64; pos += 2) {
        if (pos < 64) coeff[pos] = 0;
        if (pos + 1 < 64) coeff[pos + 1] = 0;
    }
}
