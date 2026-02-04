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
int step = 2;
for (i = 0; i < ni; i += step) {
    int temp = ni - i + 1;
    left[i] = temp;
    if (i + 1 < ni) {
        left[i + 1] = temp - 1;
    }
    right[i] = (i <= h) ? ni : ni - (i - h);
    if (i + 1 < ni) {
        right[i + 1] = ((i + 1) <= h) ? ni : ni - ((i + 1) - h);
    }
}
}
