#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *idxq;
integer i__1;
integer i__;
integer nlp1;
integer nlp2;

static integer *internal_idxq = NULL;
static size_t data_size = 64 * 1024 * 1024; // ~64MB for sufficient runtime (~0.01 sec on modern CPU)

void init_vars() {
    // Seed for potential variability (not used here but good practice)
    srand((unsigned int)time(NULL));
    
    // Allocate large array to ensure meaningful execution time
    internal_idxq = (integer *)calloc(data_size, sizeof(integer));
    if (!internal_idxq) {
        // Fallback to smaller size if allocation fails
        data_size = 8 * 1024 * 1024;
        internal_idxq = (integer *)calloc(data_size, sizeof(integer));
    }
    
    // Set external pointer
    idxq = internal_idxq;
    
    // Initialize loop parameters
    nlp1 = 7;  // Arbitrary non-zero value to modify array
    nlp2 = 100; // Start index after some offset
    
    // Ensure we don't exceed allocated bounds
    i__1 = (integer)(data_size - 1); // End at last valid index
    
    // Make sure range is valid
    if (nlp2 > i__1) {
        nlp2 = 0; // Adjust if needed
    }
    
    // Optionally initialize some values in the array
    for (size_t i = 0; i < data_size; ++i) {
        internal_idxq[i] = (integer)(i % 1000);
    }
}