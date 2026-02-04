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
for (int k = 0; k < 1; ++k) {
    for (i = 0; i < ni; ++i) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
}
