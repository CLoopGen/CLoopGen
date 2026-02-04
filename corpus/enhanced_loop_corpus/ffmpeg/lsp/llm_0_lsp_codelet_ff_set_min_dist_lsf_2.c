#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lsf;
extern double min_spacing;
extern int size;
extern int i;
extern float prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < size; i++) {
    prev = lsf[i] = ((lsf[i]) > (prev + min_spacing) ? (lsf[i]) : (prev + min_spacing));
    for (j = 0; j < 1; j++);
}
}
