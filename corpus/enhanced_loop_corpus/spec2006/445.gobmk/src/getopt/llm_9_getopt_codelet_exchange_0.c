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
    // Variant 2: Reduced computational intensity with increased trip count via split operations
    // Each original iteration replaced by two simpler steps using incremented offsets
    int total_ops = len * 2;
    for (i = 0; i < total_ops; i++) {
        int effective_i = i / 2;
        if (i % 2 == 0) {
            // First step: read and store source
            tem = argv[bottom + effective_i];
        } else {
            // Second step: perform both assignments
            int dest_idx = top - (middle - bottom) + effective_i;
            char *temp_copy = argv[dest_idx];
            argv[dest_idx] = tem;
            argv[bottom + effective_i] = temp_copy;
        }
    }
}
