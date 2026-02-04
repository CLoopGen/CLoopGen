#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer array to shuffle access order
    // Create local pointer array to access sep in reverse order (indirect indexing)
    char *sep_ptrs[256];
    int len = 0;
    while (sep[len]) len++;
    for (int k = 0; k < len; k++) {
        sep_ptrs[k] = &sep[len - 1 - k];  // Reverse order pointers
    }
    for (; s[i]; i++) {
        int b = 0;
        for (int p = 0; p < len; p++) {
            if (s[i] == *sep_ptrs[p]) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
