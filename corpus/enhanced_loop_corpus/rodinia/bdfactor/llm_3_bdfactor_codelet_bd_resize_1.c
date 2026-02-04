#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lb;
extern int i;
extern int j;
extern int l;
extern int umin;
extern double **Av;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t stride = 2; // Strided access with step size 2
for (i = lb + 1 , l = 1; l <= umin; i++ , l++)
    for (j = 0; j < l; j += stride)
        Av[i][j] = 0.; // Strided memory access: update only every 'stride'-th element in each row
}
