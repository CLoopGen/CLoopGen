#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Precompute indirect indices (reversed order access)
    for (int i = 0; i < keylen; i++) {
        indices[i] = keylen - 1 - i;
    }

    s = 0;
    for (int i = 0; i < keylen; i++) {
        int idx = indices[i];  // Indirect access
        if (key[idx] == '{') {
            s = idx;
            break;
        }
        s = idx + 1; // Maintain logical progression
    }

    free(indices);
}
