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
    if (hash->nhash > 0) {
        i = 0;
        for (;;) {
            hash->table[i] = ((void *)0);
            i++;
            if (i >= hash->nhash) break;
        }
    }
}
