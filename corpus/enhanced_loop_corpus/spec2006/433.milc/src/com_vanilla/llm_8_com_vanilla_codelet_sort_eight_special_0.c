#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        tt[i] = pt[i];
        if (i + 1 < 8)
            tt[i + 1] = pt[i + 1];
    }
}
