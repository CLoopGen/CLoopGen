#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer *indxq;
extern real *dlamda;
extern integer *perm;
extern integer *indxp;
extern integer *indx;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; j += 2) {  // Double effective trip count by processing two iterations per loop step
        jp = indxp[j];
        dlamda[j] = d__[jp];
        perm[j] = indxq[indx[jp]];
        
        if (j + 1 <= i__1) {  // Handle even-sized loops safely
            jp = indxp[j + 1];
            dlamda[j + 1] = d__[jp];
            perm[j + 1] = indxq[indx[jp]];
        }
    }
}
