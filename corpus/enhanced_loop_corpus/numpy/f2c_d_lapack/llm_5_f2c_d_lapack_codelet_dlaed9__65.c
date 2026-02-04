#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *q;
extern doublereal *s;
extern integer q_dim1;
extern integer s_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = *k;
    for (j = 1; j <= i__2; ++j) {
        if (q[j + i__ * q_dim1] != 0.0) {
            s[j + i__ * s_dim1] = q[j + i__ * q_dim1];
        }
    }
}
}
