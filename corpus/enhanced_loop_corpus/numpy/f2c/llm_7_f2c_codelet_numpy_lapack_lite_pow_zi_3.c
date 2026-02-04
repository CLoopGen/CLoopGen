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
    doublereal prev_qr = q.r, prev_qi = q.i;
    for (u = n; ; ) {
        if (u & 1) {
            t = prev_qr * x.r - prev_qi * x.i;
            q.i = prev_qr * x.i + prev_qi * x.r;
            q.r = t;
        }
        if (u >>= 1) {
            t = x.r * x.r - x.i * x.i;
            x.i = 2 * x.r * x.i;
            x.r = t;
        } else
            break;
        prev_qr = q.r;
        prev_qi = q.i;
    }
}
