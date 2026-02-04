#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Band {
    int msf;
    int res[2];
    int scfi[2];
    int scf_idx[2][3];
    int Q[2];
} Band;

extern int i;
extern int cnt;
extern Band *bands;
extern int maxband;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping (simulating non-contiguous or reordered access)
    int *indices = (int*)malloc(maxband * sizeof(int));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < maxband; i++)
        indices[i] = i;

    // Simulate a shuffled or indirect access pattern (here: reverse order)
    for (i = 0; i < maxband; i++) {
        int idx = indices[maxband - 1 - i]; // Reverse traversal via indirection
        if (bands[idx].res[0] || bands[idx].res[1])
            cnt++;
    }

    free(indices);
}
