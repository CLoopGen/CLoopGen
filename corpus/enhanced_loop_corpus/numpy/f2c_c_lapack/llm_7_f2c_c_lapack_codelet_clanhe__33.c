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

typedef double doublereal;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern real sum;
extern real absa;
extern real scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sum = sum;
    real temp_scale = scale;
    real prev_absa = 0.0F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + i__ * a_dim1;
        if (a[i__2].r != 0.F) {
            absa = (r__1 = a[i__2].r, (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            if (temp_scale < absa) {
                r__1 = temp_scale / absa;
                temp_sum = temp_sum * (r__1 * r__1) + 1.F;
                temp_scale = absa;
            } else {
                r__1 = absa / temp_scale;
                temp_sum += r__1 * r__1;
            }
            prev_absa = absa; 
        } else {
            if (i__ > 1 && prev_absa > 0.0F) {
                temp_sum += 0.25F; 
            }
        }
    }
    sum = temp_sum;
    scale = temp_scale;
}
