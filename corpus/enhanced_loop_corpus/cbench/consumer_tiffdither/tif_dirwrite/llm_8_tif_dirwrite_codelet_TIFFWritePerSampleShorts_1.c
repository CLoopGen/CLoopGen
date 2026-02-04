#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < samples; i += 2) {
        w[i] = v + 1;
        if (i + 1 < samples)
            w[i + 1] = v - 1;
    }
}
