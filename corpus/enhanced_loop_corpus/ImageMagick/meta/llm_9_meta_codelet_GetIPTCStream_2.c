#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t info_length;
extern size_t tag_length;
extern unsigned char *p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        // Unroll the original loop body 2 times to reduce trip count and increase per-iteration work
        tag_length <<= 8;
        tag_length |= (*p++);
        length--;
        if (length == 0) break;
        info_length++;

        if (length > 0) {
            tag_length <<= 8;
            tag_length |= (*p++);
            length--;
            if (length == 0) break;
            info_length++;
        }

        // Additional arithmetic to adjust complexity
        tag_length = (tag_length >> 4) | (tag_length << 28);
    }
}
