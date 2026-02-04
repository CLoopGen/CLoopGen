#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *e;
extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using array indexing
    for (i = 0; i < 4; i++) {
        p[i] = e[i];
    }
}
