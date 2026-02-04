#include <stdio.h>

#include <inttypes.h>

struct gki_elem {
    char *key;
    int idx;
    struct gki_elem *nxt;
};


typedef struct {
    struct gki_elem **table;
    int primelevel;
    int nhash;
    int nkeys;
} GKI;

extern GKI *hash;
extern struct gki_elem *ptr;
extern int i;
extern int nkeys;
extern int nempty;
extern int maxkeys;
extern int minkeys;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Introduce loop-carried dependence via cumulative key count and staggered min/max updates
    int cumul_keys = 0;

    // Artificially create a sequential dependency on a running total (introduce loop-carried RAW/WAW)
    for (i = 0; i < hash->nhash; i++) {
        nkeys = 0;
        ptr = hash->table[i];

        // Create data dependency chain: each iteration depends on prior maxkeys/minkeys
        int bucket_size = 0;
        while (ptr != ((void *)0)) { // Using while internally but not as outer loop
            bucket_size++;
            ptr = ptr->nxt;
        }
        nkeys = bucket_size;

        // Force ordered update: current max/min affect next iteration’s decisions (loop-carried dependency)
        if (i == 0) {
            maxkeys = nkeys;
            minkeys = nkeys;
        } else {
            if (nkeys > maxkeys)
                maxkeys = nkeys; // WAW on maxkeys with dependence on prior value
            if (nkeys < minkeys)
                minkeys = nkeys; // WAW on minkeys with dependence
        }

        // Carry forward cumulative sum (RAW: cumul_keys used and updated each iteration)
        cumul_keys += nkeys;
        if (nkeys == 0)
            nempty++; // Still independent increment
    }

    // Slight use of derived value to justify cumul_keys (e.g., could be for avg, though not stored)
}
