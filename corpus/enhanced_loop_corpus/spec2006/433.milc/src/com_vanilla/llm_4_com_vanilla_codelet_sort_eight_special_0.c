#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            tt[i] = pt[i];
        } else {
            continue;
        }
    }
}
