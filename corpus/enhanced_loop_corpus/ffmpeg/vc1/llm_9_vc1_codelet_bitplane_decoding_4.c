#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern uint8_t *planep;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < stride * height * 2; i += 2) {
        int idx = i % (stride * height);
        planep[idx] = !planep[idx];
    }
}
