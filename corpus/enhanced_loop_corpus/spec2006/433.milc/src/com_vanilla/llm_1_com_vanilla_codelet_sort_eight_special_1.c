#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 1; i++) {
        for (int k = 0; k <= 1; k++) {
            int idx = 2 * i + k;
            if (idx <= 3) {
                pt[idx] = tt[2 * idx];
                pt[(7 - (idx))] = tt[2 * idx + 1];
            }
        }
    }
}
