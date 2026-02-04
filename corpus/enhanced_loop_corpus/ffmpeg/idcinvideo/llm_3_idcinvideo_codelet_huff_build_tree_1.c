#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct hnode {
    int count;
    unsigned char used;
    int children[2];
} hnode;

extern hnode *hnodes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int *indices = (int*)malloc((256 * 2) * sizeof(int));
    for (i = 0; i < 256 * 2; i++) {
        indices[i] = i; // Populate indirect indices
    }
    for (i = 0; i < 256 * 2; i++) {
        hnodes[indices[i]].used = 0;
    }
    free(indices);
}
