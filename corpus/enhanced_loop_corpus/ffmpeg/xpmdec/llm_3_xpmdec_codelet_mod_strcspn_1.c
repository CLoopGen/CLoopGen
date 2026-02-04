#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *string;
extern  char *reject;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic and index remapping
    // Uses an array of offsets to simulate indirect traversal, avoiding direct [i+1] patterns
    const int offset[] = {0, 1, 2}; // Common offsets used in comparisons
    const int num_offsets = 3;
    char *p = string;
    if (!p) return;

    // Precompute length for safe bounds checking
    int str_len = 0;
    while (p[str_len]) str_len++;

    for (i = 0; i < str_len; i++) {
        if (i + 1 < str_len && *(p + i + offset[0]) == '/' && *(p + i + offset[1]) == '*') {
            i += 2;
            for (; i < str_len; i++) {
                int cond1 = (i < str_len) ? *(p + i) : 0;
                int cond2 = (i + 1 < str_len) ? *(p + i + offset[1]) : 0;
                if (cond1 == '*' && cond2 == '/')
                    break;
            }
            i++; // Skip past '*/'
        } else if (i + 1 < str_len && *(p + i) == '/' && *(p + i + 1) == '/') {
            i += 2;
            for (; i < str_len; i++) {
                if (*(p + i) == '\n') {
                    i++;
                    break;
                }
            }
        } else {
            int match = 0;
            char *r = reject;
            if (r) {
                for (j = 0; r[j]; j++) {
                    if (*(p + i) == r[j]) {
                        match = 1;
                        break;
                    }
                }
            }
            if (match) break;
        }
    }
}
