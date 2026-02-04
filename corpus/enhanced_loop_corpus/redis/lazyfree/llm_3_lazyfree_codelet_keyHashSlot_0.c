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
    for (int i = 0; i < keylen; i++) {
        indices[i] = i; // direct mapping, but allows for reordering or non-consecutive patterns
    }
    s = 0;
    for (int i = 0; i < keylen; i++) {
        s = indices[i];
        if (key[s] == '{')
            break;
    }
    free(indices);
}
