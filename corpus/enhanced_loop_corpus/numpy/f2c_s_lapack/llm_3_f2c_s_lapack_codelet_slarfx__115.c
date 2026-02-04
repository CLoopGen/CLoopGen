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
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real v5;
extern real v6;
extern real v7;
extern real v8;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer base = c_dim1;
integer offsets[8] = {base, base << 1, base * 3, base << 2, base * 5, base * 6, base * 7, base << 3};

for (j = 1; j <= i__1; ++j) {
    sum = 0.0f;
    for (integer k = 0; k < 8; ++k) {
        integer idx = j + offsets[k];
        real vk = *(real*)((char*)&v1 + k * sizeof(real)); // Access v1..v8 via offset
        sum += vk * c__[idx];
    }
    for (integer k = 0; k < 8; ++k) {
        integer idx = j + offsets[k];
        real tk = *(real*)((char*)&t1 + k * sizeof(real)); // Access t1..t8 via offset
        c__[idx] -= sum * tk;
    }
}
}
