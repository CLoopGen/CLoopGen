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
for (i = 0; i < 8; i += 2) {
    int idx = i / 2;
    dst2013[idx] += stride2013[idx] * srcSliceY / 2;
    dst1023[idx] += stride1023[idx] * srcSliceY / 2;
}
}
