#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_ii = ii;
    for (; temp_ii < (521 + (8 * 8) - 1) / (8 * 8); temp_ii++) {
        for (int j = 0; j < 1; j++) {
            (t_d)[temp_ii] = 0;
        }
    }
    ii = temp_ii;
}
