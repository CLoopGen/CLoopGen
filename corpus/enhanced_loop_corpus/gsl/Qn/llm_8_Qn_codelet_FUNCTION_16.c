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
for (i = 1; i <= ni; ++i) {
    int idx = ni - i;
    left[idx] = i + 1;
    right[idx] = ((ni - i) <= h) ? ni : ni - ((ni - i) - h);
}
}
