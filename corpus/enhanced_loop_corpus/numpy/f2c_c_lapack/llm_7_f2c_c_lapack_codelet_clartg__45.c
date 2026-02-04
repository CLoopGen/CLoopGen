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

extern singlecomplex *r__;
extern integer i__1;
extern singlecomplex q__1;
extern integer i__;
extern real safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real local_r = r__->r;
real local_i = r__->i;
for (i__ = 1; i__ <= i__1; ++i__) {
    local_r = safmx2 * local_r;
    local_i = safmx2 * local_i;
}
r__->r = local_r;
r__->i = local_i;
}
