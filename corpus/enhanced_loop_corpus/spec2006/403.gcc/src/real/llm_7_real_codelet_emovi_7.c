#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6 - 1; i++) {
        *(q + i) = *(p - i);  // Introduce loop-carried dependence via index arithmetic
                              // Each iteration depends on 'i', creating a more rigid loop-carried dependency
    }
}
