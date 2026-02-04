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
    // Variant 2: Indirect memory access via an index array (simulating gather-style access)
    // We create a local index map that defines the order of traversal,
    // here simply simulating reversed access order (could be generalized).
    ptrdiff_t count = 0;
    ptrdiff_t indices[512]; // Assume max input size; in practice, dynamic allocation or larger static
    unsigned char *temp;

    // Build indirect access list (reverse order of valid bytes until null terminator)
    for (temp = content; *temp != '\x00' && count < 512; temp++) {
        indices[count++] = temp - content;
    }

    // Traverse using indirect indices (now reverse order)
    for (ptrdiff_t j = 0; j < count; j++) {
        c = (int)content[indices[j]];
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
