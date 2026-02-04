#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *cx;
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_r, temp_i;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ - 1;
        temp_r = cx[i__].r;
        temp_i = cx[i__].i;
        if (i__2 >= 1) {
            cy[i__2].r += temp_r;
            cy[i__2].i += temp_i;
        }
    }
}
