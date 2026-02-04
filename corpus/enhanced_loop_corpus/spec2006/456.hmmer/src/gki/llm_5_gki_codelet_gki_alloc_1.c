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
    for (i = 0; i < hash->nhash; i++) {
        if (i % 2 == 0) {
            hash->table[i] = ((void *)0);
            continue;
        }
        hash->table[i] = ((void *)0);
    }
}
