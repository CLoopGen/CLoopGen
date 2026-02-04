#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated pointer chasing)
    size_t indices[4096];
    size_t count = 0;
    for (char *temp = start_color; *temp != '\x00' && count < 4095; temp++) {
        indices[count++] = temp - start_color;
    }
    indices[count] = 0; // Sentinel

    size_t idx = 0;
    while (idx < count) { // Note: using 'while' only for control, not replacing for semantics
        p = &start_color[indices[idx]];
        if (*p == '(') {
            idx++;
            for (; idx < count && start_color[indices[idx]] != ')'; idx++)
                ;
            if (idx >= count) {
                break;
            }
        } else if (*p == '-' || *p == '\x00') {
            break;
        }
        idx++;
    }
}
