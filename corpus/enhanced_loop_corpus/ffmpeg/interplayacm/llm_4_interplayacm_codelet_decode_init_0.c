#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x3[27];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x3 = 0; x3 < 3; x3++) {
        for (x2 = 0; x2 < 3; x2++) {
            for (x1 = 0; x1 < 3; x1++) {
                if (x1 % 2 == 0) {
                    mul_3x3[x1 + x2 * 3 + x3 * 9] = x1 + (x2 << 4) + (x3 << 8);
                } else {
                    mul_3x3[x1 + x2 * 3 + x3 * 9] = 0;
                }
            }
        }
    }
}
