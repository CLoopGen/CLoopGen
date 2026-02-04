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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic with pre-computed increments
    uint16_t **d2013 = dst2013;
    uint16_t **d1023 = dst1023;
    int *s2013 = stride2013;
    int *s1023 = stride1023;
    
    for (i = 0; i < 4; i++) {
        *(d2013++) += (*s2013++) * srcSliceY / 2;
        *(d1023++) += (*s1023++) * srcSliceY / 2;
    }
}
