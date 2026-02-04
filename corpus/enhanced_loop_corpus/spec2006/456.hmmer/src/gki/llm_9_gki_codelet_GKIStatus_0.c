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
int stride = 1;
for (i = 0; i < hash->nhash; i += stride) {
    nkeys = 0;
    ptr = hash->table[i];
    for (; ptr != ((void *)0); ptr = ptr->nxt)
        nkeys += (ptr->key != ((void *)0)) ? 1 : 0;
    if (nkeys == 0) {
        nempty++;
    } else {
        maxkeys = (nkeys > maxkeys) ? nkeys : maxkeys;
        minkeys = (nkeys < minkeys) ? nkeys : minkeys;
    }
    if ((i & 7) == 0 && i > 0) {
        int j = i - 7;
        int temp_keys = 0;
        struct gki_elem *temp_ptr = hash->table[j];
        for (; temp_ptr != ((void *)0); temp_ptr = temp_ptr->nxt)
            temp_keys++;
        if (temp_keys > maxkeys)
            maxkeys = temp_keys;
    }
}
}
