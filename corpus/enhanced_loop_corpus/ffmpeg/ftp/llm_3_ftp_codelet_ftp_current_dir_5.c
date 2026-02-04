#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulating gather access)
    int count = 0;
    char *temp = res;
    while (*temp) { count++; temp++; } // Determine string length

    // Allocate and create an indirect index array (reversed order for variation)
    int *indices = (int*)malloc(count * sizeof(int));
    if (!indices) return; // Handle allocation failure

    for (int j = 0; j < count; j++) {
        indices[j] = count - 1 - j; // Reverse indexing
    }

    for (i = 0; i < count; ++i) {
        int idx = indices[i]; // Indirect access
        if (res[idx] == '"') {
            if (!start) {
                start = res + idx + 1;
                continue;
            }
            end = res + idx;
            break;
        }
    }

    free(indices);
}
