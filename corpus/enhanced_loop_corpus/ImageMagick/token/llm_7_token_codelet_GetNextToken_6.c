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
    char *temp_p = p;
    ssize_t temp_i = i;
    const size_t max_index = extent - 1;
    const char *const end_bound = start + max_index;

    for (; (temp_p < q) && (*temp_p != ',') && (temp_p < end_bound); temp_p++) {
        // Introduce write-after-write dependency by updating index only after store
        if (temp_i < (ssize_t)max_index) {
            token[temp_i] = *temp_p;
            temp_i += 1;  // Loop-carried WAW dependency on temp_i
        }
    }

    // Update shared state only at the end to eliminate per-iteration RAW dependencies
    p = temp_p;
    i = temp_i;
}
