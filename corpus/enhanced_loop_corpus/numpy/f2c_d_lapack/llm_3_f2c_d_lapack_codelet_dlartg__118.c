#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *r__;
extern integer i__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer *indices = (integer*)malloc(i__1 * sizeof(integer));
    for (integer j = 0; j < i__1; ++j) {
        indices[j] = j + 1;
    }
    for (i__ = 0; i__ < i__1; ++i__) {
        if (indices[i__] >= 1) {
            *r__ *= safmx2;
        }
    }
    free(indices);
}
