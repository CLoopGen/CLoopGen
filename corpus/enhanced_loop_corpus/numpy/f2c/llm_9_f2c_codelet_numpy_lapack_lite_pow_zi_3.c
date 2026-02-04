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
    for (u = n; u != 0; ) {
        if (u & 1) {
            t = q.r * x.r - q.i * x.i;
            q.i = q.r * x.i + q.i * x.r;
            q.r = t;
            // Additional arithmetic to increase computational intensity
            q.r += 0.1 * x.i;
            q.i -= 0.1 * x.r;
        }
        if (u >>= 1) {
            // Unroll squaring computation with redundant operations
            doublereal xr = x.r, xi = x.i;
            t = xr * xr - xi * xi;
            x.i = 2.0 * xr * xi;
            x.r = t;
            // Introduce extra dependent arithmetic (simulate higher intensity)
            x.r = (x.r + x.i) * 0.5;
            x.i = (x.i - x.r) * 0.5 + x.i;
        } else
            break;
    }
}
