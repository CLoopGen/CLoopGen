#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *restrict start;
extern  size_t extent;
extern char *restrict token;
extern  char *restrict p;
extern ssize_t i;
extern char escape;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t local_i = i; // Eliminate loop-carried WAW dependency on shared `i`
    size_t p_offset;
    for (p++; *p != '\x00'; p++) {
        p_offset = (size_t)(p - start);
        if (p_offset >= (extent - 1))
            break;

        if ((*p == '\\') && ((*(p + 1) == escape) || (*(p + 1) == '\\'))) {
            p++;
        }
        else if (*p == escape) {
            p++;
            break;
        }

        if (local_i < (ssize_t)(extent - 1)) {
            token[local_i] = *p; // Write to token using local index
            local_i++; // Update local copy to remove RAW/WAW on global `i`
        }
    }
    i = local_i; // Single write-back to maintain semantic correctness
}
