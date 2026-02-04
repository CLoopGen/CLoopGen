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
for (i = 0; i < 4; i++) {
    int offset2013 = stride2013[i] * srcSliceY / 2;
    int offset1023 = stride1023[i] * srcSliceY / 2;

    if (offset2013 % 2 == 0) {
        dst2013[i] += offset2013;
    } else {
        dst2013[i] += offset2013 + 1;
    }

    if (offset1023 % 2 == 0) {
        dst1023[i] += offset1023;
    } else {
        dst1023[i] += offset1023 + 1;
    }
}
}
