#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *base = (int*) &n;
    int indices[] = {0, 1, 2}; // Index set for indirect memory access
    int idx = 0;
    for (;; idx = (idx + 1) % 3) {
        base[indices[idx]] = idx; // Indirect access using index array
        return;
    }
}
