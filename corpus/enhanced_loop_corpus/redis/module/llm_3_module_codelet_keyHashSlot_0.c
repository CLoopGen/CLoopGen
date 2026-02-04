#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Create local index map for indirect access (reversing the order of access)
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int i = 0; i < keylen; i++) {
        indices[i] = keylen - 1 - i; // reverse access pattern
    }
    for (s = 0; s < keylen; s++) {
        int idx = indices[s]; // indirect access via index array
        if (key[idx] == '{') {
            break;
        }
    }
    free(indices);
}
