#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern int t;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect (index array-based) memory access via pointer arithmetic
    // Create local index arrays to simulate indirect access (emulated via offset)
    int indices[2000];
    for (int i = 0; i < n; ++i) {
        indices[i] = i; // identity mapping for indirect access (can be randomized in real use cases)
    }
    for (t = 0; t < n; ++t) {
        int it = indices[t]; // indirect access to t
        for (r = 0; r < n; ++r) {
            int ir = indices[r]; // indirect access to r
            for (s = 0; s < n; ++s) {
                int is = indices[s]; // indirect access to s
                (*B)[ir][is] += A[ir][it] * A[is][it];
            }
        }
    }
}
