#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array
    // Simulates indirect access pattern using an auxiliary index mapping
    // Assumes that the maximum content length is known and bounded (here we use a fixed bound for simplicity)
    // In practice, index_map would be precomputed based on access reordering needs (e.g., bit-reversed, scrambled)

    #define MAX_INPUT_LEN 8192
    static size_t index_map[MAX_INPUT_LEN];
    size_t len = 0;
    unsigned char *ptr;

    // Build indirect access map: simply sequential here but structured to allow arbitrary reordering
    for (ptr = content; ptr < content + MAX_INPUT_LEN && *ptr != '\x00'; ptr++) {
        index_map[len++] = ptr - content;
    }

    // Traverse using indirect indexing
    for (size_t i = 0; i < len; i++) {
        c = content[index_map[i]];
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
