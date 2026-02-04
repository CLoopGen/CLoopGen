#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *vt2;
extern integer vt2_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nlp2 <= i__1) {
        i__ = nlp2;
        for (int repeat = 0; repeat < 1; ++repeat) {
            for (; i__ <= i__1; ++i__) {
                vt2[ktemp + i__ * vt2_dim1] = vt2[i__ * vt2_dim1 + 1];
            }
        }
    }
}
