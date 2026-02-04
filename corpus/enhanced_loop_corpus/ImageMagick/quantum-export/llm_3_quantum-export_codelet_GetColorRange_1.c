#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping using a fixed stride permutation
    // Simulates irregular/indirect access pattern by using an index mapping array (conceptually)
    // Since we cannot allocate dynamically and must avoid while, use compile-time fixed indirect indices
    #define MAX_INDIRECT 1024
    static const size_t indices[MAX_INDIRECT] = {
        0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45,
        48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93,
        // Generate a strided but bounded indirect access pattern
        96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141
        // Remaining elements initialized to 0 by static
    };
    size_t i;
    for (i = 0; i < MAX_INDIRECT; i++) {
        size_t idx = indices[i];
        if (idx >= 4096) continue;
        if (start_color[idx] == '-' || start_color[idx] == '\x00')
            break;
        if (start_color[idx] == '(') {
            // Traverse sequentially from next position until ')' or '\x00'
            size_t j = idx + 1;
            for (; j < 4096 && start_color[j] != ')' && start_color[j] != '\x00'; j++)
                ;
            if (j >= 4096 || start_color[j] == '\x00') {
                p = &start_color[j];
                break;
            }
            // Update tracking pointer
            p = &start_color[j];
        }
        p = &start_color[idx];
    }
    // Ensure p is set even if loop completes without inner break
    if (i == MAX_INDIRECT) p = &start_color[indices[i-1]];
}
