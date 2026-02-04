#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 3; i++) {
        if (i % 2 == 0) {
            pt[i] = tt[2 * i];
        } else {
            continue;
        }
        pt[(7 - i)] = tt[2 * i + 1];
    }
}
