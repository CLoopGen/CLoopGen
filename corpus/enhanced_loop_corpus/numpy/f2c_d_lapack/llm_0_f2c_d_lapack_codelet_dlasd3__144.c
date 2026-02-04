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
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        for (int j = 0; j < 1; ++j) {
            vt2[ktemp + i__ * vt2_dim1] = vt2[i__ * vt2_dim1 + 1];
        }
    }
}
