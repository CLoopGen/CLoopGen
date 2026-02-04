#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = ni * 2;
for (i = 0; i < limit; i += 2) {
    left[i/2] = ni - i/2 + 1;
    right[i/2] = (i/2 <= h) ? ni : ni - (i/2 - h);
}
}
