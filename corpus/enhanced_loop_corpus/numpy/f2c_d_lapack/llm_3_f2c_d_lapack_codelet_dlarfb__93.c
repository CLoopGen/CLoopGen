#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern doublereal *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer lastc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer *index_map = (integer*)malloc(i__1 * sizeof(integer));
for (j = 0; j < i__1; ++j) {
    index_map[j] = j + 1;
}
for (j = 0; j < i__1; ++j) {
    integer mapped_j = index_map[j];
    for (i__ = 1; i__ <= lastc; ++i__) {
        c__[mapped_j + i__ * c_dim1] -= work[i__ + mapped_j * work_dim1];
    }
}
free(index_map);
}
