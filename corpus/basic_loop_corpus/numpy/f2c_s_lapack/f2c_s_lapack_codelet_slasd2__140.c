#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt;
extern real *vt2;
extern integer vt_dim1;
extern integer vt2_dim1;
extern integer i__1;
extern real c__;
extern integer i__;
extern integer m;
extern real s;
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    vt[m + i__ * vt_dim1] = -s * vt[nlp1 + i__ * vt_dim1];
    vt2[i__ * vt2_dim1 + 1] = c__ * vt[nlp1 + i__ * vt_dim1];
}

}
