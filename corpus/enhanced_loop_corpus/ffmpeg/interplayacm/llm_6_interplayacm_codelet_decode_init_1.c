#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x5[125];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_index = 0;
    for (x3 = 0; x3 < 5; x3++) {
        int offset_x3 = x3 * 25;
        for (x2 = 0; x2 < 5; x2++) {
            int offset_x2 = x2 * 5;
            for (x1 = 0; x1 < 5; x1++) {
                base_index = x1 + offset_x2 + offset_x3;
                mul_3x5[base_index] = x1 + (x2 << 4) + (x3 << 8);
            }
        }
    }
}
