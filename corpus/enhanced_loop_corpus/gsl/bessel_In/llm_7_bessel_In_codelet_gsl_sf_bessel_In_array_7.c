#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;
extern double eax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *res = result_array;
    double local_eax = eax;
    int range = nmax - nmin;
    for (j = 0; j <= range; j += 2) {
        if (j + 1 <= range) {
            res[j]     *= local_eax;
            res[j + 1] *= local_eax;
        } else {
            res[j] *= local_eax;
        }
    }
}
