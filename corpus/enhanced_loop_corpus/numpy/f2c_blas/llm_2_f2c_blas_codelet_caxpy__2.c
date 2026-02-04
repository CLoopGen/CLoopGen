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

extern singlecomplex *ca;
extern singlecomplex *cx;
extern singlecomplex *cy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ + 1 <= i__1) {
        // Strided access by step of 2: process two elements per iteration with stride
        integer idx1 = i__;
        integer idx2 = i__ + 1;

        // First element
        q__2.r = ca->r * cx[idx1].r - ca->i * cx[idx1].i;
        q__2.i = ca->r * cx[idx1].i + ca->i * cx[idx1].r;
        q__1.r = cy[idx1].r + q__2.r;
        q__1.i = cy[idx1].i + q__2.i;
        cy[idx1].r = q__1.r;
        cy[idx1].i = q__1.i;

        // Second element
        q__2.r = ca->r * cx[idx2].r - ca->i * cx[idx2].i;
        q__2.i = ca->r * cx[idx2].i + ca->i * cx[idx2].r;
        q__1.r = cy[idx2].r + q__2.r;
        q__1.i = cy[idx2].i + q__2.i;
        cy[idx2].r = q__1.r;
        cy[idx2].i = q__1.i;
    } else {
        // Handle odd-sized case
        integer idx = i__;
        q__2.r = ca->r * cx[idx].r - ca->i * cx[idx].i;
        q__2.i = ca->r * cx[idx].i + ca->i * cx[idx].r;
        q__1.r = cy[idx].r + q__2.r;
        q__1.i = cy[idx].i + q__2.i;
        cy[idx].r = q__1.r;
        cy[idx].i = q__1.i;
    }
}
}
