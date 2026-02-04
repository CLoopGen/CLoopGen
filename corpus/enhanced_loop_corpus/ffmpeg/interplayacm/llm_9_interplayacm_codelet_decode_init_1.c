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
    for (x3 = 0; x3 < 3; x3++) // Reduced trip count to increase computational density per iteration
        for (x2 = 0; x2 < 5; x2++)
            for (x1 = 0; x1 < 5; x1 += 2) { // Step by 2 to reduce iterations and increase stride
                int temp = (x1 << 1) + (x2 << 3) + x3; // More arithmetic operations per element
                mul_3x5[x1 + x2 * 5 + x3 * 25] = temp & 0xFF; // Bitwise operation added
            }
}
