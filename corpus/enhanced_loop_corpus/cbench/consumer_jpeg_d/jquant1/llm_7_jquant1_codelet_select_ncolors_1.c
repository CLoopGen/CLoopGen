#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long prev_temp = temp;
    for (volatile int j = 1; j < nc; j++) {
        prev_temp = prev_temp * iroot;
        temp = prev_temp;
    }
}
