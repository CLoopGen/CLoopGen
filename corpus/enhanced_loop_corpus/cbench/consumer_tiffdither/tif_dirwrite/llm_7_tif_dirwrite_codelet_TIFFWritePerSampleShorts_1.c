#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 local_v = v;
    for (i = 0; i < samples; i += 2) {
        if (i + 1 < samples) {
            w[i]     = local_v;
            w[i + 1] = local_v;
        } else {
            w[i] = local_v;
        }
    }
}
