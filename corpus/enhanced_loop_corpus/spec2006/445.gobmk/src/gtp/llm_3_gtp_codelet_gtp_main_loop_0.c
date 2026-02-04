#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via pointer array (simulated indexing through pointer table)
    char *ptr_table[1000];
    int len = 0;
    // Build indirect access table
    for (int j = 0; j < 1000 && line[j]; j++) {
        ptr_table[len++] = &line[j];
    }

    // Traverse using indirect pointers
    for (i = 0, p = line; i < len; i++) {
        char c = *ptr_table[i];
        if (c == 9)
            *p++ = 32;
        else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
            continue;
        else if (c == '#')
            break;
        else
            *p++ = c;
    }
}
