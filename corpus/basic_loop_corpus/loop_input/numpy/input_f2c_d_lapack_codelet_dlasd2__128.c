#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__;
integer *nl;
doublereal *d__;
doublereal *z__;
doublereal *alpha;
doublereal *vt;
integer *idxq;
integer vt_dim1;
integer nlp1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01 sec runtime

    nl = (integer*)malloc(sizeof(integer));
    *nl = (integer)(data_size / sizeof(doublereal)); // derive loop count from data size

    if (*nl < 1) *nl = 1;

    size_t array_len = *nl + 2;

    d__ = (doublereal*)calloc(array_len, sizeof(doublereal));
    z__ = (doublereal*)calloc(array_len, sizeof(doublereal));
    idxq = (integer*)calloc(array_len, sizeof(integer));
    vt_dim1 = *nl + 1;
    size_t vt_len = (*nl + 1) * (vt_dim1 + 1);
    vt = (doublereal*)calloc(vt_len, sizeof(doublereal));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    nlp1 = *nl + 1;

    for (size_t i = 1; i < array_len; ++i) {
        d__[i] = (doublereal)(i * 2);
        idxq[i] = (integer)(i * 3);
    }

    for (size_t i = 1; i <= (size_t)nlp1; ++i) {
        vt[i + nlp1 * vt_dim1] = (doublereal)(i * 4);
    }

    i__ = *nl;
}