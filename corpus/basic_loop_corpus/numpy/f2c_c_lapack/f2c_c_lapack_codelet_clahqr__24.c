#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *ilo;
extern singlecomplex *h__;
extern integer h_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = *ilo; j <= i__1; ++j) {
    i__2 = j + 2 + j * h_dim1;
    h__[i__2].r = 0.F , h__[i__2].i = 0.F;
    i__2 = j + 3 + j * h_dim1;
    h__[i__2].r = 0.F , h__[i__2].i = 0.F;
}

}
