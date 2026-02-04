#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int even_order;
extern unsigned int ii;
extern unsigned int jj;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - traverse column-wise (stride of even_order) to expose different cache behavior
    for (jj = 0; jj < even_order; jj++)
        for (ii = 0; ii < even_order; ii++) {
            if (ii == jj)
                zz[ii * even_order + jj] = 4 * (ii + 1) * (ii + 1);
            else if (ii == jj + 1 || ii + 1 == jj)
                zz[ii * even_order + jj] = qq;
        }
}
