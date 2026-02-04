#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern complex **A_me;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
complex * restrict row_i = A_me[lo] + i;
complex * restrict row_j = A_me[lo] + j;
int64_t stride = (char*)A_me[lo + 1] - (char*)A_me[lo]; 
for (k = lo; k <= hi; k++) {
    tmp = *(complex*)((char*)row_i + (k - lo) * stride);
    *(complex*)((char*)row_i + (k - lo) * stride) = *(complex*)((char*)row_j + (k - lo) * stride);
    *(complex*)((char*)row_j + (k - lo) * stride) = tmp;
}
}
