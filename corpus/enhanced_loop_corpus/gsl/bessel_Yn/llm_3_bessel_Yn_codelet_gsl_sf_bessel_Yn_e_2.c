#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double two_over_x;
extern double bym;
extern double by;
extern double byp;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) access using an index map
    // Simulate indirect access through an index permutation array
    int *index_map = (int*)malloc(n * sizeof(int));
    double *by_vals = (double*)calloc(n, sizeof(double));
    double *bym_vals = (double*)calloc(n, sizeof(double));
    double *byp_vals = (double*)calloc(n, sizeof(double));

    // Create reverse mapping for indirect access
    for (int i = 0; i < n; i++) {
        index_map[i] = n - 1 - i;  // Reverse order access
    }

    // Initialize base case at logical j=0
    by_vals[index_map[0]] = by;
    bym_vals[index_map[0]] = bym;

    for (j = 1; j < n; j++) {
        int curr_idx = index_map[j];
        int prev_idx = index_map[j-1];

        byp_vals[curr_idx] = j * two_over_x * by_vals[prev_idx] - bym_vals[prev_idx];
        bym_vals[curr_idx] = by_vals[prev_idx];
        by_vals[curr_idx] = byp_vals[curr_idx];
    }

    // Retrieve final values from last accessed location
    int final_idx = index_map[n-1];
    byp = byp_vals[final_idx];
    bym = bym_vals[final_idx];
    by = by_vals[final_idx];

    free(index_map);
    free(by_vals);
    free(bym_vals);
    free(byp_vals);
}
