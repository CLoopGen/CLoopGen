#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern int rnk;
extern  int *n;
extern  int *niphys;
extern  int *nophys;
extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering independent iterations
    // Access pattern modified to promote spatial locality with direct sequential updates
    INT *is_arr = (INT*)malloc(rnk * sizeof(INT));
    INT *os_arr = (INT*)malloc(rnk * sizeof(INT));
    INT *n_arr = (INT*)malloc(rnk * sizeof(INT));

    // Pre-load values to enable consecutive write pattern in reverse order
    for (int j = 0; j < rnk; ++j) {
        is_arr[j] = x->dims[j].is;
        os_arr[j] = x->dims[j].os;
        n_arr[j] = x->dims[j].n;
    }

    // Perform computation with reversed dependency resolution using local arrays
    for (i = rnk - 1; i > 0; --i) {
        is_arr[i - 1] = is_arr[i] * niphys[i];
        os_arr[i - 1] = os_arr[i] * nophys[i];
        n_arr[i - 1] = n[i - 1];
    }

    // Write back results consecutively to structure
    for (i = 0; i < rnk - 1; ++i) {
        x->dims[i].is = is_arr[i];
        x->dims[i].os = os_arr[i];
        x->dims[i].n = n_arr[i];
    }

    free(is_arr);
    free(os_arr);
    free(n_arr);
}
