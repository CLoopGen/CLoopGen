#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulate indirect access via precomputed indices stored in a local array
    int indices[2500];
    for (int j = 0; j < n; j++) {
        indices[j] = j; // Identity mapping to simulate reordered access (could be permuted)
    }
    for (i = 0; i < n; i++) {
        int idx = indices[i]; // Indirect access through index array
        if (idx < n) {
            seq[idx] = (base)((i + 1) % 4);
        }
    }
}
