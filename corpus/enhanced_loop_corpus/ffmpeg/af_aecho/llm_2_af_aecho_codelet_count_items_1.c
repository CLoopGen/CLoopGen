#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (simulating non-consecutive access)
    // We traverse the string by skipping every other character, still checking for '|'
    for (p = item_str; *p; p += 2) {
        if (*p == '|')
            (*nb_items)++;
        // Handle potential odd-length strings safely
        if (*(p + 1) && *(p + 1) == '|')
            (*nb_items)++;
    }
}
