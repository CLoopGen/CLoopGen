#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct AVFilterFormats {
    unsigned int nb_formats;
    int *formats;
    unsigned int refcount;
    struct AVFilterFormats ***refs;
};

typedef struct AVFilterFormats AVFilterFormats;

AVFilterFormats *b;
AVFilterFormats *ret;
int i;

static AVFilterFormats **refs_b_space;
static AVFilterFormats **refs_ret_space;
static AVFilterFormats *dummy_formats;

void init_vars() {
    // Allocate dummy_formats to act as the target of refs
    dummy_formats = (AVFilterFormats *)calloc(1, sizeof(AVFilterFormats));
    if (!dummy_formats) exit(1);

    // Set refcount to achieve desired runtime (~0.01 seconds)
    // Each iteration does several pointer operations; assume ~10 cycles per iteration.
    // On a 3 GHz CPU, 0.01 seconds ≈ 30e6 cycles → use refcount ≈ 3e6 / 10 = 300k iterations.
    unsigned int refcount_val = 300000;

    b = (AVFilterFormats *)calloc(1, sizeof(AVFilterFormats));
    ret = (AVFilterFormats *)calloc(1, sizeof(AVFilterFormats));
    if (!b || !ret) exit(1);

    b->refcount = refcount_val;
    ret->refcount = 0;

    // Allocate refs arrays: array of pointers to (pointer to AVFilterFormats)
    refs_b_space = (AVFilterFormats **)calloc(refcount_val, sizeof(AVFilterFormats **));
    refs_ret_space = (AVFilterFormats **)calloc(refcount_val, sizeof(AVFilterFormats **));
    if (!refs_b_space || !refs_ret_space) exit(1);

    // Initialize each element of b->refs to point to a valid *** location
    for (unsigned int j = 0; j < refcount_val; j++) {
        refs_b_space[j] = dummy_formats;
    }

    b->refs = (AVFilterFormats ***)calloc(refcount_val, sizeof(AVFilterFormats ***));
    ret->refs = (AVFilterFormats ***)calloc(refcount_val, sizeof(AVFilterFormats ***));
    if (!b->refs || !ret->refs) exit(1);

    // Assign each b->refs[i] to point to refs_b_space[i], which holds a pointer to dummy_formats
    for (unsigned int j = 0; j < refcount_val; j++) {
        b->refs[j] = &refs_b_space[j];
    }

    // Similarly, initialize ret->refs to point to its own space
    for (unsigned int j = 0; j < refcount_val; j++) {
        ret->refs[j] = &refs_ret_space[j];
    }
}