#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int filter_limit;
int *bounding_values;
int x;

void init_vars() {
    filter_limit = 131072; // Adjusted to ensure loop runs ~0.01s (approx 1MB array)
    bounding_values = (int*)calloc(2 * filter_limit + 1, sizeof(int));
    if (!bounding_values) {
        exit(1);
    }
    // Adjust pointer so that [-x] accesses valid memory
    bounding_values += filter_limit;
}

void loop(); // Forward declaration

// Ensure proper linkage and execution when called from main in another file