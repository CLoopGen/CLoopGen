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
int indices[4] = {0, 2, 1, 3};
for (j = 0; j < 4; ++j) {
    int idx = indices[j];
    doublereal val1 = (d__1 = equiv_1[idx], (d__1 >= 0 ? d__1 : -d__1));
    doublereal val2 = (d__2 = equiv_0[idx], (d__2 >= 0 ? d__2 : -d__2));
    if (val1 + val2 > cmax) {
        cmax = val1 + val2;
        icmax = idx + 1;
    }
}
}
