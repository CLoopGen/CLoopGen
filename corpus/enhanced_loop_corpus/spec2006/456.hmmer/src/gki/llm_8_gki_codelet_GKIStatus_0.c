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



void loop(){
for (i = 0; i < hash->nhash; i += 2) {
    nkeys = 0;
    ptr = hash->table[i];
    if (ptr != ((void *)0)) {
        do {
            nkeys++;
            ptr = ptr->nxt;
        } while (ptr != ((void *)0));
    }
    if (nkeys == 0)
        nempty++;
    else {
        if (nkeys > maxkeys)
            maxkeys = nkeys;
        if (nkeys < minkeys)
            minkeys = nkeys;
    }
    if (i + 1 < hash->nhash) {
        int local_nkeys = 0;
        ptr = hash->table[i + 1];
        while (ptr != ((void *)0)) {
            local_nkeys++;
            ptr = ptr->nxt;
        }
        if (local_nkeys == 0)
            nempty++;
        else {
            if (local_nkeys > maxkeys)
                maxkeys = local_nkeys;
            if (local_nkeys < minkeys)
                minkeys = local_nkeys;
        }
    }
}
}
