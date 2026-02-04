#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp_prev = temp;
    for (volatile int j = 1; j < nc; j++) {
        temp_prev = temp_prev * iroot + j;
        temp = temp_prev;
    }
}
