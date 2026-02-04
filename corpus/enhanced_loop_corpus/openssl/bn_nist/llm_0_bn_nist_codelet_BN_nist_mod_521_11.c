#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int outer_ii;
    for (outer_ii = 0; outer_ii < (521 + (8 * 8) - 1) / (8 * 8); outer_ii++) {
        for (ii = outer_ii; ii < outer_ii + 1; ii++) {
            (t_d)[ii] = 0;
        }
    }
}
