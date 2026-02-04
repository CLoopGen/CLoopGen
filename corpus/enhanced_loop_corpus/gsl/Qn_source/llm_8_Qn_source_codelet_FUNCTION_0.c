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
int j;
for (i = 0; i < ni; ++i) {
    left[i] = ni - i + 1;
    for (j = 0; j < h; ++j) {
        if (j <= i) {
            right[i] = ni - (i - j);
        }
    }
    if (i <= h) {
        right[i] = ni;
    }
}
}
