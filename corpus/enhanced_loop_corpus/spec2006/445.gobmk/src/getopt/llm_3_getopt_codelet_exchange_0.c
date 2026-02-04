#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern int top;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Introduce an auxiliary index array to enable indirect addressing.
    // This simulates scenarios where access patterns are data-dependent or reordered.
    int indices[len];
    for (i = 0; i < len; i++) {
        indices[i] = i;  // Could be randomized or reordered in real use cases
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];  // Use indirection
        tem = argv[bottom + idx];
        argv[bottom + idx] = argv[top - (middle - bottom) + idx];
        argv[top - (middle - bottom) + idx] = tem;
    }
}
