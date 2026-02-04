#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double dat[2];
} gsl_complex;

extern  double c[];
extern  int len;
extern  gsl_complex z;
extern int i;
extern gsl_complex ans;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    // This changes the sequential backward traversal to a strided one
    int stride = 2;
    for (i = (len - 1) % stride; i > 0; i = (i - stride + len) % len) {
        int prev_index = (i - 1 + len) % len; // safe index wrap-around
        double tmp = c[prev_index] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
        if (i < stride) break; // prevent infinite loop due to stride
    }
}
