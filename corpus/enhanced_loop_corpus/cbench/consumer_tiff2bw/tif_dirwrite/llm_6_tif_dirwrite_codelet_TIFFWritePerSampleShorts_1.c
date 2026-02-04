#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 temp = v;
    for (i = 0; i < samples; i++) {
        temp += w[i];      // Introduce RAW dependency: each read of w[i] feeds into temp
        w[i] = temp;       // WAW: w[i] is written after prior iteration's write if unrolled
    }
}
