#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t1;
extern int half_size;
extern  uint8_t *t2;
extern uint8_t *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < half_size; i++) {
        s[2*i] = *(t1 + i);
        s[2*i] += 1; // Introduce WAW and RAW: artificial dependency via write-read on same location
        s[2*i] = *(t1 + i); // Redundant write (WAW with previous line), creating loop-carried dependence through value reuse
        s[2*i + 1] = *(t2 + i);
    }
}
