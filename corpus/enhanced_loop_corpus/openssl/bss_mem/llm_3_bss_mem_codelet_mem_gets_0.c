#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    int indices[256]; // Local index buffer, assuming reasonable bound
    for (int k = 0; k < j && k < 256; k++) {
        indices[k] = k;
    }
    for (i = 0; i < j && i < 256; i++) {
        if (p[indices[i]] == '\n') {
            i++;
            break;
        }
    }
}
