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
    integer temp_inc = *incv; // Remove repeated memory access (eliminate loop-carried WAW on *incv)
    integer temp_i = i__;
    for (;;){
        i__1 = temp_i;
        if (!(lastv > 0 && (v[i__1].r == 0.F && v[i__1].i == 0.F)))
            break;
        --lastv;
        temp_i -= temp_inc; // Introduce local variable to break direct WAR/WAW on i__
    }
    i__ = temp_i; // Update original i__ only after loop
}
