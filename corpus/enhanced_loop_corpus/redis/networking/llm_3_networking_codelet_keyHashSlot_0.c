#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < keylen; i++) {
        indices[i] = i;  // Populate index array
    }
    for (s = 0; s < keylen; s++) {
        if (key[indices[s]] == '{')  // Use indirect access
            break;
    }
    free(indices);
}
