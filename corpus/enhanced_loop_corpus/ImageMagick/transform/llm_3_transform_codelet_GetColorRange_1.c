#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index lookup)
    // Simulate indirect traversal using a precomputed stride map (compile-time constant offsets)
    #define MAX_INDIRECT 1024
    static const ptrdiff_t indices[MAX_INDIRECT] = {
        0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45,
        48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93,
        // Pattern continues roughly every 3 bytes, simulating non-sequential access
    };
    char *base = start_color;
    int i;
    for (i = 0; i < MAX_INDIRECT; i++) {
        char *ptr = base + indices[i];
        if (ptr >= start_color + 4096) break;
        if (*ptr == '-' || *ptr == '\x00') {
            p = ptr;
            break;
        }
        if (*ptr == '(') {
            ptr++;
            for (; (ptr < start_color + 4096) && (*ptr != ')') && (*ptr != '\x00'); ptr++)
                ;
            if (*ptr == '\x00') {
                p = ptr;
                break;
            }
            p = ptr;
        } else {
            p = ptr;
        }
    }
    if (i == MAX_INDIRECT) p = base + indices[MAX_INDIRECT - 1];
}
