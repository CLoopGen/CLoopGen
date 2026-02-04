#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index proxy)
    // We simulate indirect access by treating an auxiliary offset array as indices, but since we can't define new globals,
    // we use a local fixed-offset lookup table to model irregular access.
    int offsets[] = {0, 1, 3, 4, 7, 8, 12, 15}; // Example non-uniform strides
    int num_offsets = sizeof(offsets) / sizeof(offsets[0]);
    char *base = start_color;
    int i;

    for (i = 0; i < num_offsets; i++) {
        p = base + offsets[i];
        if (*p == '\x00' || *p == '-')
            break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }

    // Fallback linear scan if more data needs processing (in case offsets don't cover all)
    for (p = base + (num_offsets > 0 ? offsets[num_offsets - 1] + 1 : 0);
         (*p != '-') && (*p != '\x00');
         p++) {
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
}
