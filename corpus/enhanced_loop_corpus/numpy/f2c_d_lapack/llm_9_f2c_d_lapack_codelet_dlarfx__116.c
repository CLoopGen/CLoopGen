#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal t5;
extern doublereal t6;
extern doublereal t7;
extern doublereal t8;
extern doublereal t9;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal v9;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer k;
for (j = 1; j <= i__1; ++j) {
    sum = 0.0;
    for (k = 1; k <= 9; ++k) {
        doublereal vk = 0.0, tk = 0.0;
        switch(k) {
            case 1: vk = v1; tk = t1; break;
            case 2: vk = v2; tk = t2; break;
            case 3: vk = v3; tk = t3; break;
            case 4: vk = v4; tk = t4; break;
            case 5: vk = v5; tk = t5; break;
            case 6: vk = v6; tk = t6; break;
            case 7: vk = v7; tk = t7; break;
            case 8: vk = v8; tk = t8; break;
            case 9: vk = v9; tk = t9; break;
        }
        if (vk != 0.0) {
            sum += vk * c__[j + c_dim1 * k];
        }
    }
    for (k = 1; k <= 9; ++k) {
        doublereal vk = 0.0, tk = 0.0;
        switch(k) {
            case 1: vk = v1; tk = t1; break;
            case 2: vk = v2; tk = t2; break;
            case 3: vk = v3; tk = t3; break;
            case 4: vk = v4; tk = t4; break;
            case 5: vk = v5; tk = t5; break;
            case 6: vk = v6; tk = t6; break;
            case 7: vk = v7; tk = t7; break;
            case 8: vk = v8; tk = t8; break;
            case 9: vk = v9; tk = t9; break;
        }
        if (tk != 0.0) {
            c__[j + c_dim1 * k] -= sum * tk;
        }
    }
}
}
