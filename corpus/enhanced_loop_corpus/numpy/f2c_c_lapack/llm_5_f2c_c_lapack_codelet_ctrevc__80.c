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

extern integer *n;
extern singlecomplex *t;
extern singlecomplex *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + *n;
        i__3 = i__ + i__ * t_dim1;
        if (t[i__3].r >= 0.0f) {
            work[i__2].r = t[i__3].r;
            work[i__2].i = t[i__3].i;
        } else {
            work[i__2].r = 0.0f;
            work[i__2].i = 0.0f;
        }
    }
}
