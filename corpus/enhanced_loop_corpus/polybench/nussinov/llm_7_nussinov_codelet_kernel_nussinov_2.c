#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int table[2500][2500];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i--) {
    for (j = i + 1; j < n; j++) {
        // Eliminate WAW and RAW hazards by deferring updates with private accumulation
        int local_update = table[i][j];

        // Introduce artificial loop-carried dependency via chained update
        if (j - 1 >= 0)
            local_update = (local_update > table[i][j-1]) ? local_update : table[i][j-1];

        if (i + 1 < n)
            local_update = (local_update > table[i+1][j]) ? local_update : table[i+1][j];

        if (j - 1 >= 0 && i + 1 < n) {
            int match = ((seq[i] + seq[j]) == 3) ? 1 : 0;
            int prev_diag = table[i+1][j-1];
            if (i < j - 1)
                prev_diag += match;
            local_update = (local_update > prev_diag) ? local_update : prev_diag;
        }

        // Break loop-carried dependence in k-loop by unrolling assumption and using reduction
        int max_split = local_update;
        for (k = i + 1; k < j; k++) {
            int candidate = table[i][k] + table[k+1][j];
            if (candidate > max_split)
                max_split = candidate;
        }
        local_update = max_split;

        // Final write to shared state — single WAW write per (i,j)
        table[i][j] = local_update;
    }
}
}
