#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

typedef struct {
    real r;
    real i;
} singlecomplex;

singlecomplex *v;
integer *incv;
integer i__1;
integer i__;
integer lastv;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for v (each element is 8 bytes)
    v = (singlecomplex *)aligned_alloc(32, data_size * sizeof(singlecomplex));
    if (!v) abort();

    // Fill with zeros except near the end to control loop iterations
    for (size_t idx = 0; idx < data_size; ++idx) {
        v[idx].r = 0.0f;
        v[idx].i = 0.0f;
    }

    // Set a non-zero value near the beginning to stop the loop early when reached
    // Ensure the loop doesn't run too long: place first non-zero at index 1000
    size_t safe_start = 1000;
    v[safe_start].r = 1.0f;

    // Allocate and initialize incv as a constant increment (e.g., 1)
    incv = (integer *)malloc(sizeof(integer));
    if (!incv) abort();
    *incv = 1;

    // Initialize loop indices
    i__ = data_size - 1;          // start near the end
    lastv = data_size;             // total number of elements

    // Ensure initial i__1 is valid and within bounds
    i__1 = i__;
}