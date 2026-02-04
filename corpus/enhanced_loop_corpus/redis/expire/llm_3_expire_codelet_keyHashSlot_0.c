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
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < keylen; i++)
        indices[i] = i;  // Direct mapping for realism, could be shuffled in real scenarios

    for (s = 0; s < keylen; s++) {
        if (key[indices[s]] == '{') {
            s = indices[s];  // Map back to original array index
            free(indices);
            return;
        }
    }
    free(indices);
    s = keylen; // Not found
}
