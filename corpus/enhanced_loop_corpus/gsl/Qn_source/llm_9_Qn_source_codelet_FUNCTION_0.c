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
int stride = 2;
for (i = 0; i < ni; i += stride) {
    left[i] = ni - i + 1;
    right[i] = ni;
    if (i + 1 < ni) {
        left[i + 1] = ni - (i + 1) + 1;
        right[i + 1] = ni - ((i + 1) - h);
    }
}
}
