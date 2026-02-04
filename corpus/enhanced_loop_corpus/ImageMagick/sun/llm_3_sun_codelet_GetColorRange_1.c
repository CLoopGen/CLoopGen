#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulating gather access)
    // Precompute valid indices within bounds to simulate indirect traversal
    ptrdiff_t indices[4096];
    int count = 0;
    for (int i = 0; i < 4096; i++) {
        indices[count++] = i;
    }

    char *temp_p;
    for (int idx = 0; idx < count; idx++) {
        temp_p = start_color + indices[idx];
        if ((*temp_p == '-') || (*temp_p == '\x00')) {
            p = temp_p;
            break;
        }
        if (*temp_p == '(') {
            temp_p++;
            while ((temp_p - start_color) < 4096 && (*temp_p != ')') && (*temp_p != '\x00')) {
                temp_p++;
            }
            p = temp_p;
            if (*temp_p == '\x00') {
                break;
            }
        }
        p = temp_p;
    }
}
