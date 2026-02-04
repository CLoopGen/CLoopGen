#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *q;
extern real *s;
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
        real temp_sum = 0.0f;
        for (j = 1; j <= i__2; ++j) {
            temp_sum += q[j + i__ * q_dim1];
        }
        for (j = 1; j <= i__2; ++j) {
            s[j + i__ * s_dim1] = temp_sum;
        }
    }
}
