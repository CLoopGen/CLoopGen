#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt2;
extern integer vt2_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        if (ktemp != 0) {
            vt2[ktemp + i__ * vt2_dim1] = vt2[i__ * vt2_dim1 + 1];
        } else {
            vt2[i__ * vt2_dim1] = vt2[i__ * vt2_dim1 + 1];
        }
    }
}
