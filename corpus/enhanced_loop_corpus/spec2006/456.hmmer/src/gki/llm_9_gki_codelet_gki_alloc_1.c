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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1 << 2; // Unroll by 4
    int remainder = hash->nhash % stride;
    struct gki_elem **tbl = hash->table;

    for (i = 0; i < hash->nhash - remainder; i += stride) {
        tbl[i]     = ((void *)0);
        tbl[i + 1] = ((void *)0);
        tbl[i + 2] = ((void *)0);
        tbl[i + 3] = ((void *)0);
    }

    // Handle remaining elements
    for (; i < hash->nhash; i++) {
        hash->table[i] = ((void *)0);
    }
}
