#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulated with pointer arithmetic)
    // Build virtual index map assuming max reasonable string length
    int len = 0;
    const char *n = name;
    while (n[len]) len++;
    
    int indices[512]; // Assume max length
    for (int i = 0; i < len && i < 512; i++) {
        indices[i] = i; // Direct mapping, could be randomized or reordered in real use
    }

    base = name;
    for (int i = 0; i < len && i < 512; i++) {
        char c = name[indices[i]];
        if (c == '/') {
            base = (char *)&name[indices[i] + 1];
        }
    }
}
