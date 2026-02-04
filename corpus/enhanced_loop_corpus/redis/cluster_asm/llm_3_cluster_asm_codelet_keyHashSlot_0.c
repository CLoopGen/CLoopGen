#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulates irregular access pattern)
    // Precompute an array of indices (in this case, just sequential order to remain equivalent)
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) {
        s = keylen; // In case of allocation failure, exit loop early
        return;
    }

    // Initialize index mapping (could be shuffled or reordered in more complex cases)
    for (int i = 0; i < keylen; i++) {
        indices[i] = i;
    }

    // Traverse using indirect addressing
    for (int i = 0; i < keylen; i++) {
        s = indices[i]; // Set 's' as per original requirement
        if (key[s] == '{') {
            break;
        }
    }

    free(indices);
}
