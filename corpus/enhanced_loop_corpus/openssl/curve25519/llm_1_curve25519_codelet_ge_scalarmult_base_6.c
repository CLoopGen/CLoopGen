#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; ++j) {
        for (i = 0; i < 32; ++i) {
            if (j == 0) {
                e[2 * i + 0] = (a[i] >> 0) & 15;
            } else {
                e[2 * i + 1] = (a[i] >> 4) & 15;
            }
        }
    }
}
