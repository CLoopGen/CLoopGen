#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *leaf;
extern char *sep;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    int len = 0;
    const char *base = name;
    while (base[len]) len++;  // Compute length manually without using library functions

    // Simulate indirect access by reversing the traversal order (reverse indexing)
    for (int i = len - 1; i >= 0; i--) {
        const char *p_indirect = base + i;
        if (*p_indirect == '\'')
            sep = (char*)p_indirect, leaf = (char*)p_indirect + 1;
        else if (*p_indirect == ':' && *(p_indirect + 1) == ':')
            sep = (char*)p_indirect, leaf = (char*)p_indirect + 2;
    }
}
