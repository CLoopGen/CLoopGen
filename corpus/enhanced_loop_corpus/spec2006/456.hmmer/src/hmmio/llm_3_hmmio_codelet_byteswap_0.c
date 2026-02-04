#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect addressing via index array (simulated with calculated indices)
    int *indices = (int*)__builtin_alloca(nbytes * sizeof(int));
    for (int i = 0; i < nbytes; i++) {
        indices[i] = i;
    }
    for (x = 0; x < nbytes / 2; x++) {
        int forward_idx = indices[x];
        int reverse_idx = indices[nbytes - x - 1];
        byte = swap[reverse_idx];
        swap[reverse_idx] = swap[forward_idx];
        swap[forward_idx] = byte;
    }
}
