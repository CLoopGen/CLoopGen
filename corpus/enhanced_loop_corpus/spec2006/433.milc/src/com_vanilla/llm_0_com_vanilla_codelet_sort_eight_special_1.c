#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i <= 3; i++) {
            pt[i] = tt[2 * i];
            pt[(7 - (i))] = tt[2 * i + 1];
        }
    }
}
