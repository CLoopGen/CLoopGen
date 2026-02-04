#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffTable {
    int code;
    int length;
} HuffTable;

extern HuffTable *distincts;
extern int i;
extern int j;
extern int nbits[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index remapping table (simulated with reverse traversal order)
    // Access elements in reverse order using indirect indexing to change access pattern
    int idx;
    j = 0;
    for (idx = 255; idx >= 0; idx--) {
        i = idx; // Map iteration index indirectly
        if (nbits[i] > 0) {
            distincts[j].code = i;
            distincts[j].length = nbits[i];
            j++;
        }
    }
}
