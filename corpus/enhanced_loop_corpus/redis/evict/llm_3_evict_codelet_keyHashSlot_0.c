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
    // Create local index map on stack (only if keylen is small; for realism, cap at reasonable size)
    #define MAX_LEN 1024
    if (keylen <= 0 || keylen > MAX_LEN) return;
    
    int indices[MAX_LEN];
    // Initialize indirect access pattern: reverse order access
    for (int i = 0; i < keylen; i++) {
        indices[i] = keylen - 1 - i;
    }
    
    // Traverse using indirect addressing
    for (s = 0; s < keylen; s++) {
        int idx = indices[s];  // Reverse access: from end to start
        if (key[idx] == '{') {
            s = keylen - idx - 1; // Adjust 's' to reflect original position in reverse
            break;
        }
    }
}
