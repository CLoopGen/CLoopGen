#include <stdio.h>

#include <inttypes.h>

extern char **rseqs;
extern int nseq;
extern char **aseqs;
extern int alen;
extern int M;
extern int **ins;
extern int *master_ins;
extern int apos;
extern int rpos;
extern int idx;
extern int statepos;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access Pattern
    // Use an index array to access ins and master_ins indirectly, simulating irregular memory access.
    // Introduce an auxiliary index mapping to traverse state positions in a shuffled order.

    int shuffle_order[256];  // Assuming M < 256
    int temp_count;

    // Precompute indirect access order (e.g., reverse order for indirect pattern)
    for (temp_count = 0; temp_count <= M; temp_count++) {
        shuffle_order[temp_count] = M - temp_count;
    }

    for (idx = 0; idx < nseq; idx++) {
        apos = rpos = 0;

        // Traverse state positions via shuffled (indirect) indexing
        for (temp_count = 0; temp_count <= M; temp_count++) {
            statepos = shuffle_order[temp_count];  // Indirect access to statepos

            // Reverse mapping to get original state index for correct data access
            int orig_statepos = M - statepos;

            // Use original indices to fetch correct insertion counts
            for (count = 0; count < ins[idx][orig_statepos]; count++)
                aseqs[idx][apos++] = rseqs[idx][rpos++];

            for (; count < master_ins[orig_statepos]; count++)
                aseqs[idx][apos++] = ' ';

            // Match character insertion based on original progression
            if (orig_statepos != M)
                aseqs[idx][apos++] = rseqs[idx][rpos++];
        }
        aseqs[idx][alen] = '\x00';
    }
}
