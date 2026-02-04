#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // We simulate indirect access by precomputing valid indices and traversing them
    ptrdiff_t indices[4096];
    ptrdiff_t count = 0;
    char *temp;

    // Precompute valid indices within bounds
    for (temp = start_color; temp - start_color < 4096 && (*temp != '-') && (*temp != '\x00'); temp++) {
        indices[count++] = temp - start_color;
    }

    // Traverse using indirect access via index array
    for (ptrdiff_t i = 0; i < count; i++) {
        p = start_color + indices[i];
        if (*(start_color + indices[i]) == '(') {
            p = start_color + indices[i] + 1;
            for (; p - start_color < 4096 && (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                break;
            }
        }
    }
}
