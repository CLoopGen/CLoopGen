#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *k;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer j;
integer l;

static doublereal *a_data = NULL;

void init_vars() {
    const integer size_hint_mb = 64;
    const integer approx_elements = (size_hint_mb * (1 << 20)) / sizeof(doublereal);
    const integer n = (integer)sqrt((double)approx_elements);
    
    i__1 = n > 1000 ? n : 1000;
    *m = i__1;
    *k = i__1 / 2;

    a_dim1 = i__1;
    integer total_size = (i__1 + 1) * (i__1 + 1);

    a_data = (doublereal*)calloc(total_size, sizeof(doublereal));
    if (!a_data) {
        exit(1);
    }

    a = a_data + a_dim1 + 1;
}

static void allocate_pointers() {
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    if (!m || !k) {
        exit(1);
    }
    *m = 512;
    *k = 256;
    i__1 = 512;
}

__attribute__((constructor))
static void constructor() {
    allocate_pointers();
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    if (a_data) {
        free(a_data);
    }
    if (m) free(m);
    if (k) free(k);
}