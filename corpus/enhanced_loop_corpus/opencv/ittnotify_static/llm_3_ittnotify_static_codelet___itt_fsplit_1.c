#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer arithmetic using an index array (simulated through offsets)
    // We simulate indirect access by creating a local offset list that reshapes access order to 'sep'
    int offsets[] = {1, 0, 3, 2, 5, 4};  // Example permutation of indices for indirect-like access
    int num_offsets = sizeof(offsets) / sizeof(offsets[0]);
    for (; s[i]; i++, (*len)++) {
        int b = 0;
        for (j = 0; j < num_offsets; j++) {
            int idx = offsets[j];
            if (sep[idx]) {  // Valid index in sep?
                if (s[i] == sep[idx]) {
                    b = 1;
                    break;
                }
            } else {
                break;
            }
        }
        if (b) break;
    }
}
