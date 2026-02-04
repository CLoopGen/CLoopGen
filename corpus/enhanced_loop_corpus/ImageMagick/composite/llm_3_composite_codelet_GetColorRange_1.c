#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // Create a local index map for indirect traversal (every 4th element first, then fill in)
    int indices[1024];
    int idx_count = 0;
    for (int i = 0; i < 4096; i += 4) {
        if (start_color[i] == '\x00' || start_color[i] == '-') break;
        indices[idx_count++] = i;
    }
    for (int stride = 1; stride < 4; stride++) {
        for (int i = stride; i < 4096; i += 4) {
            if (i >= idx_count) continue;
            if (start_color[i] == '\x00' || start_color[i] == '-') break;
            indices[idx_count++] = i;
        }
    }

    char *temp_p = start_color;
    for (int j = 0; j < idx_count; j++) {
        temp_p = start_color + indices[j];
        if (*temp_p == '(') {
            temp_p++;
            for (; temp_p < start_color + 4096 && (*temp_p != ')') && (*temp_p != '\x00'); temp_p++)
                ;
            if (*temp_p == '\x00') {
                temp_p--;
                break;
            }
        }
    }
    p = temp_p;
}
