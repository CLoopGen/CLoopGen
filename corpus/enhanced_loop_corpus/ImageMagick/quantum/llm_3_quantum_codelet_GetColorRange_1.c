#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulating gather-style access)
    // Create a static index map assuming bounded input size (simulated within safe limits)
    static uint16_t indices[2048];
    uint16_t len = 0;
    char *temp = start_color;

    // Build indirect access pattern: collect valid indices until '-' or '\0'
    while ((*temp != '-') && (*temp != '\x00') && len < 2047) {
        indices[len++] = temp - start_color;
        temp++;
    }
    indices[len] = 0; // Sentinel

    // Traverse using indirect addressing through index array
    for (uint16_t i = 0; i < len; i++) {
        char c = start_color[indices[i]];
        if (c == '(') {
            uint16_t j = indices[i] + 1;
            while ((start_color[j] != ')') && (start_color[j] != '\x00'))
                j++;
            if (start_color[j] == '\x00') {
                p = &start_color[j];
                return;
            }
            // Skip ahead in index list to continue after ')'
            while (i < len && indices[i] <= j) i++;
            if (i < len) i--; // Compensate for loop increment
        }
    }
    p = (*start_color != '\x00') ? &start_color[indices[len-1]] + 1 : start_color;
}
