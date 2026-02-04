#include <stdio.h>

#include <inttypes.h>

extern char b1[81];
extern char b2[81];
extern char *p;
extern size_t i;
extern unsigned int diff;
extern unsigned int real_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with fixed offset map)
    size_t indices[81];
    size_t num_indices = 0;
    // Build indirect access pattern: reverse order traversal
    for (size_t temp_i = 0; temp_i < 81 && b1[temp_i] != '\x00'; temp_i++) {
        indices[num_indices++] = temp_i;
    }
    // Reverse the access order
    for (size_t idx = 0; idx < num_indices; idx++) {
        i = indices[num_indices - 1 - idx]; // Reverse indexing
        if (b1[i] == b2[i] || b1[i] == ' ' || b2[i] == ' ') {
            *p++ = ' ';
            diff |= b1[i] != b2[i];
        } else {
            *p++ = '^';
            real_diff = diff = 1;
        }
    }
}
