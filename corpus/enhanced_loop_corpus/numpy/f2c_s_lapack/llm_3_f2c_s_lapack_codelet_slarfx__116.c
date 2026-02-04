#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real t5;
extern real t6;
extern real t7;
extern real t8;
extern real t9;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real v9;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Stride Loop Unrolling
    // We change access pattern to iterate over a strided layout by unrolling the inner computation
    // and accessing memory with fixed offsets relative to base index, promoting vectorization.

    const integer stride = c_dim1;
    real *c_base = c__;

    for (j = 1; j <= i__1; ++j) {
        // Precompute all array indices using compile-time constants where possible
        integer idx1 = j + stride;
        integer idx2 = j + (stride << 1);     // 2*stride
        integer idx3 = j + stride * 3;
        integer idx4 = j + (stride << 2);     // 4*stride
        integer idx5 = j + stride * 5;
        integer idx6 = j + stride * 6;
        integer idx7 = j + stride * 7;
        integer idx8 = j + (stride << 3);     // 8*stride
        integer idx9 = j + stride * 9;

        sum = v1 * c_base[idx1] + v2 * c_base[idx2] + v3 * c_base[idx3] +
              v4 * c_base[idx4] + v5 * c_base[idx5] + v6 * c_base[idx6] +
              v7 * c_base[idx7] + v8 * c_base[idx8] + v9 * c_base[idx9];

        c_base[idx1] -= sum * t1;
        c_base[idx2] -= sum * t2;
        c_base[idx3] -= sum * t3;
        c_base[idx4] -= sum * t4;
        c_base[idx5] -= sum * t5;
        c_base[idx6] -= sum * t6;
        c_base[idx7] -= sum * t7;
        c_base[idx8] -= sum * t8;
        c_base[idx9] -= sum * t9;
    }
}
