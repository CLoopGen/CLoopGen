#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *ilo = NULL;
real *h__ = NULL;
integer h_dim1;
integer i__1;
integer j;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    h_dim1 = 256;

    // Allocate h__ as a 2D array with dimensions large enough to cover index: j + 3 + j * h_dim1
    // Max j should be such that j + 3 + j * h_dim1 < allocated size
    // => j * (h_dim1 + 1) + 3 < size
    // We choose i__1 and *ilo so that the loop accesses valid range

    size_t total_elements = data_size / sizeof(real);
    
    h__ = (real*)calloc(total_elements, sizeof(real));
    if (!h__) exit(1);

    // Set *ilo and i__1 to ensure valid access within allocated bounds
    // Solve: j + 3 + j * h_dim1 < total_elements
    // => j * (h_dim1 + 1) <= total_elements - 4
    // => j <= (total_elements - 4) / (h_dim1 + 1)

    integer max_j = (total_elements - 4) / (h_dim1 + 1);
    if (max_j < 1) exit(1);

    i__1 = max_j;
    ilo = (integer*)malloc(sizeof(integer));
    if (!ilo) exit(1);
    *ilo = 1;

    // Ensure *ilo <= i__1
    if (*ilo > i__1) *ilo = i__1;
}