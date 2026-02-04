#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access via precomputed indices stored in a local array
    // Assuming stack size is sufficient for typical len values
    int indices[len];
    for (int j = 0; j < len; j++) {
        indices[j] = j; // Identity mapping, but allows reordering or non-linear patterns
    }

    for (i = 0; i < len; i++) {
        int idx = indices[i]; // Use indirect index
        tem = argv[bottom + idx];
        argv[bottom + idx] = argv[middle + idx];
        argv[middle + idx] = tem;
    }
}
