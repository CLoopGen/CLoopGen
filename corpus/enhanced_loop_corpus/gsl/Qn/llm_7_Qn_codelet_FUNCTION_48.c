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
    if (ni > 0) {
        left[0] = ni + 1;
        right[0] = (0 <= h) ? ni : ni - (0 - h);
        for (i = 1; i < ni; ++i) {
            left[i] = left[i-1] - 1;
            right[i] = (i <= h) ? ni : right[i-1] - 1;
        }
    }
}
