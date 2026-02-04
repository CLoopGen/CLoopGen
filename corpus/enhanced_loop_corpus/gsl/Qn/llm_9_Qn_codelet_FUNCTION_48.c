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
int idx, val_left, val_right;
for (i = 0; i < ni; ++i) {
    idx = ni - i;
    val_left = idx + 1;
    val_right = (i <= h) ? ni : idx - (i - h) + i;
    left[i] = val_left;
    right[i] = val_right;
}
}
