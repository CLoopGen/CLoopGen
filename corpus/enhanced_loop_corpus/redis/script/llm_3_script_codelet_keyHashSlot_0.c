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
    int *indices = (int*)malloc(sizeof(int) * keylen);
    if (!indices) return;
    for (int i = 0; i < keylen; i++)
        indices[i] = i;  // direct mapping for indirect access

    for (s = 0; s < keylen; s++) {
        if (key[indices[s]] == '{')
            break;
    }
    free(indices);
}
