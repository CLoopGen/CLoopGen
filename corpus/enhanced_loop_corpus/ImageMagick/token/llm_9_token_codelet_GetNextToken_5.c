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
    ssize_t local_i = i;
    char* local_p = p + 1;
    const size_t max_offset = extent - 1;
    const char* const end = start + max_offset;

    for (; local_p < end && *local_p != '\x00'; local_p++) {
        if ((*local_p == '\\') && (local_p + 1 < end) && (*(local_p + 1) == escape || *(local_p + 1) == '\\')) {
            local_p++;
        } else if (*local_p == escape) {
            local_p++;
            break;
        }
        if (local_i < (ssize_t)max_offset) {
            token[local_i++] = *local_p;
        }
    }

    p = local_p;
    i = local_i;
}
