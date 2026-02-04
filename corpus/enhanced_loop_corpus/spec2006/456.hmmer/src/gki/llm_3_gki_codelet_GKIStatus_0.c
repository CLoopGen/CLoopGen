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
    // Indirect access via precomputed index array to modify memory access pattern
    int *indices = (int*)__builtin_alloca(hash->nhash * sizeof(int));
    for (i = 0; i < hash->nhash; i++) {
        indices[i] = i; // Simulate indirect addressing (could be reordered in practice)
    }

    for (i = 0; i < hash->nhash; i++) {
        int actual_idx = indices[i]; // Use indirection
        nkeys = 0;
        for (ptr = hash->table[actual_idx]; ptr != ((void *)0); ptr = ptr->nxt)
            nkeys++;
        if (nkeys == 0)
            nempty++;
        if (nkeys > maxkeys)
            maxkeys = nkeys;
        if (nkeys < minkeys)
            minkeys = nkeys;
    }
}
