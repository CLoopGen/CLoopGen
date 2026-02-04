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
    i__1 = i__;
    if (!(lastv > 0 && (v[i__1].r == 0.F && v[i__1].i == 0.F)))
        break;
    --lastv;
    i__ -= *incv;
}

}
