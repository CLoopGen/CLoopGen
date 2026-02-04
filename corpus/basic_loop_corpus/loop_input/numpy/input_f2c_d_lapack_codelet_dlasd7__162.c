#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer nl_data;
doublereal *d__ = NULL;
doublereal *z__ = NULL;
doublereal *vf = NULL;
doublereal *vl = NULL;
doublereal alpha_data;
integer *idxq = NULL;
integer i__;

#define DATA_SIZE 65536

void init_vars() {
    nl_data = DATA_SIZE;
    
    d__ = (doublereal*)calloc(DATA_SIZE + 2, sizeof(doublereal));
    z__ = (doublereal*)calloc(DATA_SIZE + 2, sizeof(doublereal));
    vf = (doublereal*)calloc(DATA_SIZE + 2, sizeof(doublereal));
    vl = (doublereal*)calloc(DATA_SIZE + 2, sizeof(doublereal));
    idxq = (integer*)calloc(DATA_SIZE + 2, sizeof(integer));
    
    alpha_data = 1.5;
    
    for (int i = 1; i <= DATA_SIZE; ++i) {
        d__[i] = (doublereal)i;
        vf[i] = (doublereal)(i * 2);
        vl[i] = (doublereal)(i * 0.5);
        idxq[i] = i;
    }
    
    d__[DATA_SIZE + 1] = 0.0;
    vf[DATA_SIZE + 1] = 0.0;
    vl[DATA_SIZE + 1] = 0.0;
    z__[DATA_SIZE + 1] = 0.0;
    idxq[DATA_SIZE + 1] = 0;
}

integer *nl = &nl_data;
doublereal *alpha = &alpha_data;