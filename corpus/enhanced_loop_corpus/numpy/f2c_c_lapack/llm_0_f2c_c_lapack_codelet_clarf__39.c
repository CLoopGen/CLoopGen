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

extern singlecomplex *v;
extern integer *incv;
extern integer i__1;
extern integer i__;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        for (int nested = 0; nested < 1; ++nested) {
            i__1 = i__;
            if (!(lastv > 0 && (v[i__1].r == 0.F && v[i__1].i == 0.F)))
                goto exit_nested;
            --lastv;
            i__ -= *incv;
        }
    }
exit_nested:;
}
