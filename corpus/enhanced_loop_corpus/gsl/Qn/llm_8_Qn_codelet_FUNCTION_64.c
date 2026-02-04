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
    for (j = 0; j < i; ++j) {
        left[i] -= (j % 3);
    }
    right[i] = (i <= h) ? ni : ni - (i - h);
    for (j = 0; j < i; ++j) {
        right[i] += (j % 2);
    }
}
}
