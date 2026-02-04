#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N * 2; i += 2) {
    int idx1 = 2 * ix;
    int idx2 = 2 * ix + 1;
    float val_alpha = alpha * alpha;
    ((float *)X)[idx1] *= val_alpha;
    ((float *)X)[idx2] *= val_alpha;
    ix += incX;
}
}
