#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        Y[local_iy] = 0.;
        local_iy += incY;
    }
    iy = local_iy;  // Remove loop-carried WAW and WAR dependencies on 'iy' by deferring update
}
