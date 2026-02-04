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
    ssize_t local_i = i;
    char *local_p = p;
    const char *const local_start = start;
    const size_t local_extent = extent;
    const char *const local_q = q;
    char *const local_token = token;

    for (; (local_p < local_q) && (*local_p != ','); local_p++) {
        if (local_i < (ssize_t)(local_extent - 1)) {
            local_token[local_i] = *local_p;
            local_i++;
        }
        if ((size_t)(local_p - local_start) >= (local_extent - 1))
            break;
    }

    p = local_p;
    i = local_i;
}
