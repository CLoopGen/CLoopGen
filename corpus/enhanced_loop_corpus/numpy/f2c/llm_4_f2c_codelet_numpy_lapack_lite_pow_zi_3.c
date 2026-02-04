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
    for (u = n; ; u >>= 1) {
        t = q.r * x.r - q.i * x.i;
        q.i = q.r * x.i + q.i * x.r;
        q.r = t;
        if (!(u & 1)) {
            t = x.r * x.r - x.i * x.i;
            x.i = 2 * x.r * x.i;
            x.r = t;
        }
        if (!(u >>= 1)) break;
    }
}
