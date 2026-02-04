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
    for (x3 = 0; x3 < 5; x3++) {
        int base3 = x3 * 25;
        int val3 = x3 << 8;
        for (x2 = 0; x2 < 5; x2++) {
            int base2 = x2 * 5;
            int val2 = x2 << 4;
            for (x1 = 0; x1 < 5; x1++) {
                if ((x1 + x2 + x3) % 2 == 0) {
                    mul_3x5[x1 + base2 + base3] = x1 + val2 + val3;
                } else {
                    mul_3x5[x1 + base2 + base3] = 0;
                }
            }
        }
    }
}
