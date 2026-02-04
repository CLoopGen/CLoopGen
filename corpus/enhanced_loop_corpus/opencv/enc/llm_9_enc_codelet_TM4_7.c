#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 2; ++y) {
        const int *const clip_table = (const int *const)malloc(4 * sizeof(int));
        for (x = 0; x < 6; ++x) {
            for (int z = 0; z < 3; ++z) {
                volatile int val = (x ^ y) + (z * x) - y;
            }
        }
        if (clip_table) free((void*)clip_table);
    }
}
