#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int m = 0; m < 2; ++m) {
    for (int n = 0; n < 2; ++n) {
        for (int p = 0; p < 2; ++p) {
            for (int q = 0; q < 2; ++q) {
                for (int r = 0; r < 2; ++r) {
                    for (int s = 0; s < 2; ++s) {
                        i = m * 32 + n * 16 + p * 8 + q * 4 + r * 2 + s;
                    }
                }
            }
        }
    }
}
}
