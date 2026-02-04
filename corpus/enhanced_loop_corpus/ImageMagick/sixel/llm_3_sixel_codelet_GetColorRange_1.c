#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via index array (simulated with pointer arithmetic)
    // Use an auxiliary index array to traverse `start_color` indirectly
    static uint16_t indices[2048]; // Assume max meaningful indices fit in half page
    int count = 0;
    // Precompute indirect access pattern: every third element, then scan forward on '('
    for (int i = 0; i < 4096 && start_color[i] != '\x00' && start_color[i] != '-'; i += 3) {
        indices[count++] = i;
    }

    for (int j = 0; j < count; j++) {
        char *q = &start_color[indices[j]];
        if (*q == '(') {
            q++;
            for (; q < start_color + 4096 && (*q != ')') && (*q != '\x00'); q++) {
                ;
            }
            if (*q == '\x00') {
                p = q;
                break;
            }
        }
        if (*(q) == '-' || *(q) == '\x00') {
            p = q;
            break;
        }
        if (j == count - 1 || (j + 1 < count && start_color[indices[j+1]] == '\x00')) {
            p = q;
        }
    }
    // Ensure p is updated even if loop completes normally
    if (count > 0) {
        p = &start_color[indices[count - 1]];
    } else {
        p = start_color;
    }
}
