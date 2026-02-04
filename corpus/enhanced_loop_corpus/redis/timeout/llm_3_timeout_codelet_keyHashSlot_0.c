#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < keylen; i++) {
        indices[i] = i; // Populate indirect indices
    }
    for (int i = 0; i < keylen; i++) {
        s = indices[i]; // Use indirect addressing
        if (key[s] == '{') {
            free(indices);
            return;
        }
    }
    free(indices);
}
