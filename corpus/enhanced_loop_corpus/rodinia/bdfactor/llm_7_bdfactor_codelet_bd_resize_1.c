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
double temp;
for (i = lb + 1 , l = 1; l <= umin; i++ , l++) {
    temp = 0.0;
    for (j = 0; j < l; j++) {
        temp += (double)(j + 1);     // Eliminated WAW and WAR hazards by using local accumulation
        Av[i][j] = temp;             // Write once per element, no intra-loop carry from prior writes to Av[i][j]
    }
}
}
