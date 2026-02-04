#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ldcost;
extern int t;
extern int *A;
extern int *B;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= t; ++i)
        for (int k = 0; k < 1; ++k)
            A[B[-i]] = ldcost;
}
