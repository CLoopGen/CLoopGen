#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // We create a local array of indices to simulate indirect access pattern
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return; // Handle allocation failure

    for (int i = 0; i < keylen; i++) {
        indices[i] = i; // indices[i] holds the address offset: &key[indices[i]]
    }

    for (s = 0; s < keylen; s++) {
        if (key[indices[s]] == '{') { // Indirect access through indices
            free(indices);
            return;
        }
    }

    free(indices);
}
