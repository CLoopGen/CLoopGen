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
for (i = lb + 1, l = 1; l <= umin && i < lb + 100; i++, l++) {
    for (j = 0; j < l && j < 50; j++) {
        if (j % 2 == 0)
            Av[i][j] = 0.;
    }
}
}
