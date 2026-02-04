#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_r, temp_i;
    for (j = 1; j <= i__1; ++j) {
        temp_r = j; temp_i = j * 2;
        i__2 = *m;
        for (i__ = kk + 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            a[i__3].r = temp_r; 
            a[i__3].i = temp_i;
            temp_r += i__;  
            temp_i -= i__;  
        }
    }
}
