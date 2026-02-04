#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (224 + (8 * 8) - 1) / (8 * 8); outer++) {
        for (int inner = 0; inner < 1; inner++) {
            if (outer == ii) {
                (c_d)[ii] = 0;
                ii++;
            }
        }
    }
}
