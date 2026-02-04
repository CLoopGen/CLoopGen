#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal d__2;
extern doublereal equiv_0[4];
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i <= 1; ++i) { // Outer loop added with fixed single iteration, increasing nesting depth
        for (j = 1; j <= 4; ++j) {
            if ((d__1 = (equiv_1)[j - 1] , ((d__1) >= 0 ? (d__1) : -(d__1))) + (d__2 = (equiv_0)[j - 1] , ((d__2) >= 0 ? (d__2) : -(d__2))) > cmax) {
                cmax = (d__1 = (equiv_1)[j - 1] , ((d__1) >= 0 ? (d__1) : -(d__1))) + (d__2 = (equiv_0)[j - 1] , ((d__2) >= 0 ? (d__2) : -(d__2)));
                icmax = j;
            }
        }
    }
}
