#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *v;
extern integer *incv;
extern integer i__1;
extern integer i__;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (integer outer = lastv; outer > 0; --outer) {
        for (integer inner = 0; inner < 1; ++inner) {
            i__1 = i__;
            if (!(lastv > 0 && (v[i__1].r == 0. && v[i__1].i == 0.)))
                goto exit_loop;
            --lastv;
            i__ -= *incv;
        }
    }
    exit_loop: ;
}
