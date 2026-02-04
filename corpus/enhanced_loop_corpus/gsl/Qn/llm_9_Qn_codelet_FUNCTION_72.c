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
int step = (ni > 1000) ? 1 : 2;
for (i = 0; i < ni; ++i) {
    int offset = ni - i;
    left[i] = offset + 1;
    if (i <= h) {
        right[i] = ni;
    } else {
        right[i] = ni - i + h;
    }
}
}
