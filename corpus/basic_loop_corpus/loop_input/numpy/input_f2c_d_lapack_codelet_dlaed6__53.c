#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *tau;
integer i__;
doublereal fc;
doublereal df;
doublereal ddf;
doublereal temp;
doublereal temp1;
doublereal temp2;
doublereal temp3;
doublereal dscale[3];
doublereal zscale[3];

void init_vars() {
    // Allocate and initialize tau pointer
    tau = (doublereal*)malloc(sizeof(doublereal));
    if (!tau) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize scalar variables
    fc = 0.0;
    df = 0.0;
    ddf = 0.0;
    temp = 0.0;
    temp1 = 0.0;
    temp2 = 0.0;
    temp3 = 0.0;
    
    // Initialize arrays
    dscale[0] = 1.5;
    dscale[1] = 2.5;
    dscale[2] = 3.5;
    
    zscale[0] = 0.1;
    zscale[1] = 0.2;
    zscale[2] = 0.3;
    
    // Initialize tau value to avoid division by zero
    *tau = 0.5;
}