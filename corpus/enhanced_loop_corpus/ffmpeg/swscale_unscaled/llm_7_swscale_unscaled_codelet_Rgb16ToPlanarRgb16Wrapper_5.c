#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int srcSliceY;
extern uint16_t *dst2013[];
extern uint16_t *dst1023[];
extern int stride2013[];
extern int stride1023[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offsets[4];
    for (i = 0; i < 4; i++) {
        offsets[i] = srcSliceY / 2;
    }
    for (i = 0; i < 4; i++) {
        dst2013[i] += stride2013[i] * offsets[i];
        dst1023[i] += stride1023[i] * offsets[i];
    }
}
