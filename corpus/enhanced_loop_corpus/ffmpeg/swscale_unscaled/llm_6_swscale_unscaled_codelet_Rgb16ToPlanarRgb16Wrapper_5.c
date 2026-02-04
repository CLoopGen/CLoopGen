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
    int temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = stride2013[i] * srcSliceY / 2;
        dst2013[i] += temp[i];
        dst1023[i] += stride1023[i] * srcSliceY / 2;
    }
}
