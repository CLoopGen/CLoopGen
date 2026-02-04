#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
integer *k;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer l;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB
    const size_t element_size = sizeof(singlecomplex);
    size_t total_elements = target_bytes / element_size;
    
    // Make a_dim1 approximately square root of total elements
    a_dim1 = (integer)sqrt((double)total_elements);
    if (a_dim1 < 1) a_dim1 = 1;

    // Allocate slightly more than needed to avoid overflow
    a = (singlecomplex*)calloc(a_dim1 * a_dim1 + a_dim1 + 1, sizeof(singlecomplex));
    if (!a) exit(1);

    // Initialize loop bounds safely within allocated dimensions
    i__1 = a_dim1;
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    if (!m || !k) exit(1);

    *m = a_dim1;
    *k = a_dim1 / 2;  // Ensure k < m and valid indexing
}