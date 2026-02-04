#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t linear_to_vidc[16384];
extern int n;
extern int v;
extern  short *samples;
extern unsigned char *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = n; outer > 0; outer -= 1024) {
        int chunk = (outer < 1024) ? outer : 1024;
        for (int inner = 0; inner < chunk; inner++) {
            v = *samples++;
            *dst++ = linear_to_vidc[(v + 32768) >> 2];
            n--;
        }
    }
}
