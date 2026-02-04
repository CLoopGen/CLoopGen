#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int temp_val = b1[i];
        if (temp_val > 0 || b0[i] != b2[i]) {
            b1[i] = (16 * 4 * temp_val - 4 * (b0[i] + b2[i]) + 8 * 5 + (5 << 27)) / (5 * 16) - (1 << 23);
        } else {
            continue;
        }
    }
}
