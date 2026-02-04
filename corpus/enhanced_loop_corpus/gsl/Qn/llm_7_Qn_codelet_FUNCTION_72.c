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
int temp_left, temp_right;
for (i = 0; i < ni; ++i) {
    temp_left = ni - i + 1;
    temp_right = (i <= h) ? ni : ni - (i - h);
    left[i] = temp_left;
    right[i] = temp_right;
}
}
