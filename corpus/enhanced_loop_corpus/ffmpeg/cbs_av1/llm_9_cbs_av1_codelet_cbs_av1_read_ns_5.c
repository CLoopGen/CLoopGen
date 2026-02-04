#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int w;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < (w - 1) / step + ((w - 1) % step); i += 1) {
        int idx = i * step;
        if (idx < w - 1) bits[idx] = (v >> idx & 1) ? '1' : '0';
        if (idx + 1 < w - 1) bits[idx + 1] = (v >> (idx + 1) & 1) ? '1' : '0';
    }
}
