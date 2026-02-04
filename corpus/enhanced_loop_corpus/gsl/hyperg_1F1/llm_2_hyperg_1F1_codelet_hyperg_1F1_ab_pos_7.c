#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnp1;
extern double Mn;
extern double Mnm1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *mem = (double*)malloc(3 * sizeof(double));
    double index = a;
    for (n = a; n > 0.5; n -= 1.) {
        ptrdiff_t i = (ptrdiff_t)(index - n);
        mem[(i + 2) % 3] = (n * mem[(i + 0) % 3] - (2. * n - b + x) * mem[(i + 1) % 3]) / (b - n);
        Mnm1 = mem[(i + 2) % 3];
        Mnp1 = mem[(i + 1) % 3];
        Mn = mem[(i + 2) % 3];
    }
    free(mem);
}
