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
int temp_nempty = 0, temp_maxkeys = 0, temp_minkeys = nkeys;
for (i = 0; i < hash->nhash; i++) {
    nkeys = 0;
    struct gki_elem *current = hash->table[i];
    for (; current != ((void *)0); current = current->nxt)
        nkeys++;
    temp_nempty += (nkeys == 0);
    temp_maxkeys = (nkeys > temp_maxkeys) ? nkeys : temp_maxkeys;
    temp_minkeys = (nkeys < temp_minkeys && nkeys > 0) ? nkeys : temp_minkeys;
}
nempty = temp_nempty;
maxkeys = temp_maxkeys;
minkeys = temp_minkeys;
}
