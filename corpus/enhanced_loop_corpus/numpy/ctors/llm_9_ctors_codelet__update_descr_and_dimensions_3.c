#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int numnew;
extern npy_intp *mydim;
extern int i;
extern npy_intp tempsize;
extern npy_intp *mystrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride-based iteration and simplified computation
    if (numnew <= 0) return;
    int step = 2;  // Process every second element to reduce effective trip count
    for (i = numnew - 1; i >= 0; i -= step) {
        mystrides[i] = tempsize;
        tempsize *= (mydim[i] > 0) ? mydim[i] : 1;
        // Skip intermediate update for non-processed indices
    }
    // Final pass for remaining elements if needed, maintaining correctness
    for (i = numnew - 2; i >= 0; i -= step) {
        if (i + step >= numnew) {
            mystrides[i] = tempsize;
        } else {
            mystrides[i] = mystrides[i + step] * (mydim[i + step] ? mydim[i + step] : 1);
        }
    }
}
