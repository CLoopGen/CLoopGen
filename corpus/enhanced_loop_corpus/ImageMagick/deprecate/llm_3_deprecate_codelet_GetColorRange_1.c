#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid indices (simulated here with pointer array),
    // then traverse the string indirectly using a lookup table.

    // Simulate an indirect access pattern using an array of pointers
    char *indices[4096];
    int count = 0;
    char *temp = start_color;

    // Build indirect index map: collect all valid positions until '-' or '\0'
    while ((*temp != '-') && (*temp != '\x00')) {
        indices[count++] = temp++;
        if (*(temp-1) == '(') {
            // Skip content inside parentheses in indexing
            while ((*temp != ')') && (*temp != '\x00'))
                temp++;
            if (*temp == '\x00')
                break;
        }
    }

    // Traverse using indirect access
    for (int i = 0; i < count; i++) {
        char *ptr = indices[i];
        if (*ptr == '(') {
            for (ptr++; (*ptr != ')') && (*ptr != '\x00'); ptr++)
                ;
            if (*ptr == '\x00') {
                p = ptr;
                return;
            }
        }
    }

    // Update global pointer p to end location
    p = (*temp == '\x00' || *temp == '-') ? temp : p;
}
