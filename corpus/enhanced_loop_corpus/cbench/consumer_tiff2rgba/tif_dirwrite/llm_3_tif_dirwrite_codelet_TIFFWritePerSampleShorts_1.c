#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of the array
    for (i = samples - 1; i >= 0; i--)
        w[i] = v;
}
