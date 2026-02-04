#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *restrict start;
extern  size_t extent;
extern char *restrict token;
extern char *restrict q;
extern  char *restrict p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index offset array (simulated with pointer arithmetic)
    // Use an implicit index to simulate indirect traversal within bounds
    size_t base_offset = p - start;
    size_t limit = (q - start);
    for (size_t idx = 0; (base_offset + idx < limit) && (start[base_offset + idx] != ','); idx++) {
        char current_char = start[base_offset + idx];
        if (i < (ssize_t)(extent - 1)) {
            token[i++] = current_char;
        }
        if (base_offset + idx >= (extent - 1))
            break;
    }
    // Update p to reflect forward progress
    p = start + base_offset;
    while (p < q && *p != ',' && (size_t)(p - start) < extent) p++;
}
