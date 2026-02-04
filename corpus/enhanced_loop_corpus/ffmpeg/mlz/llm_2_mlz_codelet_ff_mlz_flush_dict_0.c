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
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    int stride = 2;
    int limit = 35023;

    // First pass: strided access
    for (i = 0; i < limit; i += stride) {
        dict[i].string_code = -1;
        dict[i].parent_code = -1;
        dict[i].match_len = 0;
    }

    // Second pass: handle any odd index if limit is odd
    for (i = 1; i < limit; i += stride) {
        dict[i].string_code = -1;
        dict[i].parent_code = -1;
        dict[i].match_len = 0;
    }
}
