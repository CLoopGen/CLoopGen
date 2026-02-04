#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Create a virtual "index map" using stride-based indirect addressing
    ptrdiff_t indices[4096];
    char *base = start_color;
    int len = 0;
    for (char *temp = base; temp < base + 4096 && *temp != '\x00'; temp++) {
        indices[len++] = temp - base;
    }

    char *ptr = base;
    int i = 0;
    for (; i < len && (*ptr != '-') && (*ptr != '\x00'); i++) {
        ptr = base + indices[i]; // Indirect access via index array
        if (*ptr == '(') {
            i++;
            for (; i < len; i++) {
                ptr = base + indices[i];
                if (*ptr == ')' || *ptr == '\x00') break;
            }
            if (i >= len || *ptr == '\x00') {
                break;
            }
        }
    }
    p = ptr;
}
