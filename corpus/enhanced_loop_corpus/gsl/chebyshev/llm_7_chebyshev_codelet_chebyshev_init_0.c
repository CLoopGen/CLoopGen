#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern double *diag;
extern double *subdiag;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_diag, temp_subdiag;
    for (i = 1; i < n; i++) {
        temp_diag = 0.;
        temp_subdiag = 0.5;
        diag[i] = temp_diag;            // Removed WAW and WAR hazards by using local temporaries; no loop-carried dependencies
        subdiag[i] = temp_subdiag;
    }
}
