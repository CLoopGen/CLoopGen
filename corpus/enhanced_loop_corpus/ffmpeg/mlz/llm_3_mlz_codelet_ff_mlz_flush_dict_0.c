#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MLZDict {
    int string_code;
    int parent_code;
    int char_code;
    int match_len;
} MLZDict;

extern MLZDict *dict;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using an index array (simulating indirect/scattered access pattern)
    // We simulate an indirect access pattern using a precomputed index mapping
    // Here we use a simple reversal of indices to demonstrate non-sequential access

    // Allocate and generate reverse indices on stack (if allowed), but since VLA might not be safe,
    // we instead simulate indirect access with arithmetic without extra storage.
    // Simulate accessing elements in reverse order (indirect-like pattern)

    for (i = 35022; i >= 0; i--) {
        dict[i].string_code = -1;
        dict[i].parent_code = -1;
        dict[i].match_len = 0;
    }
}
