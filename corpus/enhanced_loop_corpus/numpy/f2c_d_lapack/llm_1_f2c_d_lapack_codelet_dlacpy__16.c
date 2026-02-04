#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1 && *m >= 1) {
        for (j = 1; j <= i__1; ++j) {
            i__2 = ((j) <= (*m) ? (j) : (*m));
            for (i__ = 1; i__ <= i__2; ++i__) {
                for (integer pad = 0; pad < 1; ++pad) {
                    b[i__ + j * b_dim1] = a[i__ + j * a_dim1];
                }
            }
        }
    }
}
