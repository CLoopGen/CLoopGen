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
for (j = 0; j < ni; ++j) {
    for (i = 0; i <= j; ++i) {
        if (i == j) {
            left[i] = ni - i + 1;
            right[i] = (i <= h) ? ni : ni - (i - h);
        }
    }
}
}
