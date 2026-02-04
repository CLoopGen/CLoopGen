#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double out[3][3];
extern int i;
extern int j;
extern double det;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    out[i][0] *= det;
    out[i][1] *= det;
    out[i][2] *= det;
}
}
