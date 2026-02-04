#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long mag01[2];
extern unsigned long * x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long prev = x[0];
    for (i = 1; i < 25 - 7; i++) {
        unsigned long curr = x[i];
        x[i] = prev ^ (curr >> 1) ^ mag01[curr % 2];
        prev = curr;
    }
}
