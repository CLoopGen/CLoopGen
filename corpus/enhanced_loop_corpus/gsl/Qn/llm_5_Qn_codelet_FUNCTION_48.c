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
for (i = 0; i < ni; ++i) {
    left[i] = ni - i + 1;
    right[i] = ni;
    if (i > h) {
        right[i] = ni - (i - h);
    }
}
}
