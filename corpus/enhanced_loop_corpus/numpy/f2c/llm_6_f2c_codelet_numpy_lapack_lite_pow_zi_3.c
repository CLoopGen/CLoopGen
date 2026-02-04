#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer n;
extern unsigned long u;
extern double t;
extern doublecomplex q;
extern doublecomplex x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_r, temp_i;
    for (u = n; ; ) {
        if (u & 1) {
            temp_r = q.r * x.r - q.i * x.i;
            temp_i = q.r * x.i + q.i * x.r;
            q.r = temp_r;
            q.i = temp_i;
        }
        if (u >>= 1) {
            temp_r = x.r * x.r - x.i * x.i;
            temp_i = 2 * x.r * x.i;
            x.r = temp_r;
            x.i = temp_i;
        } else
            break;
    }
}
