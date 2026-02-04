#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    int *indices = (int*)malloc(keylen * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < keylen; i++)
        indices[i] = i;  // populate index array
    for (int i = 0; i < keylen; i++) {
        int idx = indices[i];  // indirect access
        if (key[idx] == '{') {
            s = idx;
            break;
        }
    }
    free(indices);
}
