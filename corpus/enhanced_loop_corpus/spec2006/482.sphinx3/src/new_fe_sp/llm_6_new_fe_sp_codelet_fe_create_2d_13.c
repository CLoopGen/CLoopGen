#include <stdio.h>

#include <inttypes.h>

extern int d1;
extern int d2;
extern int elem_size;
extern char *store;
extern char **out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW and WAR dependencies by reordering and introducing a temporary array
    char *temp[d1];  // Local temporary to create data dependency
    for (i = 0, j = 0; i < d1; i++, j += d2) {
        temp[i] = &((char *)store)[j * elem_size];
        out[i] = temp[i];  // WAW on out[i], WAR between temp[i] write and read in next iteration not applicable but dependency chain via temp introduced
    }
}
