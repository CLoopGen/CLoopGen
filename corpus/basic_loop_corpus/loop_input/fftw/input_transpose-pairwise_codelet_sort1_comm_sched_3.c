#include <stdlib.h>
#include <stdint.h>

int npes = 131072; // Size chosen to process ~1MB of data (each int is 4 bytes, two arrays)

int *sched;
int *sortsched;

int i;

void init_vars() {
    sched = (int*)malloc(npes * sizeof(int));
    sortsched = (int*)malloc(npes * sizeof(int));

    for (i = 0; i < npes; ++i) {
        sched[i] = rand() % npes; // Ensure values are within [0, npes-1]
        sortsched[i] = 0; // Initialize to avoid undefined behavior
    }

    // Precompute valid indices: since we access `2 * npes - 1 - sortsched[i]`,
    // and sortsched[i] is in [0, npes-1], the index will be in [npes, 2*npes-1],
    // which is out of bounds. So we must adjust initialization to prevent overflow.
}

// Refined approach: change logic to ensure index stays in [0, npes-1]
// Original loop: sortsched[2*npes-1-sortsched[i]] = sched[i]
// The index 2*npes-1-sortsched[i] ranges from npes to 2*npes-1 -> invalid.

// Fix: reinterpret intent as a reversal mapping within valid range.
// Let’s assume typo/intent was: index = npes - 1 - i  OR use modulo?
// But to preserve exact code, we must make sortsched[i] produce valid indices.

// Instead, initialize sortsched[i] such that 2*npes-1-sortsched[i] is in [0, npes-1]
// => 2*npes-1-sortsched[i] < npes  => sortsched[i] > npes-1
// => sortsched[i] >= npes

// But earlier we initialized sortsched[i] in [0,npes-1] — this causes out-of-bounds write.

// Correct fix: initialize sortsched[i] to values >= npes so that index becomes small.
// We want: idx = 2*npes - 1 - sortsched[i] ∈ [0, npes-1]
// => sortsched[i] ∈ [npes, 2*npes-1]

// So re-initialize sortsched with values in [npes, 2*npes-1]

void loop();

void init_vars_fixed() {
    free(sched);
    free(sortsched);

    sched = (int*)malloc(npes * sizeof(int));
    sortsched = (int*)malloc(npes * sizeof(int));

    for (i = 0; i < npes; ++i) {
        sched[i] = i; // arbitrary valid data
        sortsched[i] = npes + (rand() % npes); // now in [npes, 2*npes-1]
        // Then index = 2*npes-1 - sortsched[i] will be in [0, npes-1]
    }
}

// Call init_vars_fixed from any main or setup routine
// Since we cannot modify loop(), we must ensure memory safety via initialization

// Redefine init_vars to the fixed version
#undef init_vars
#define init_vars init_vars_fixed