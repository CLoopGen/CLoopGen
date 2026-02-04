#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct cheb_series_struct {
    double *c;
    int order;
    double a;
    double b;
    int order_sp;
};


typedef struct cheb_series_struct cheb_series;

extern double y2;
extern int eval_order;
extern  cheb_series *cs;
extern int j;
extern double d;
extern double dd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse, with wrap-around logic)
    // Simulate a strided pattern by adjusting index calculation; here we assume eval_order is even for simplicity
    int stride = 2;
    for (j = eval_order; j >= 1; j -= stride) {
        double temp = d;
        // Use modulo-like behavior to stay within valid index range
        int idx1 = j;
        int idx2 = (j - stride + 1) > 0 ? j - stride + 1 : 1;
        d = y2 * d - dd + cs->c[idx1];
        dd = temp;
        // Handle intermediate step if possible without violating constraints
        if (j - 1 >= 1 && stride == 2) {
            double temp2 = d;
            d = y2 * d - dd + cs->c[j - 1];
            dd = temp2;
        }
    }
}
