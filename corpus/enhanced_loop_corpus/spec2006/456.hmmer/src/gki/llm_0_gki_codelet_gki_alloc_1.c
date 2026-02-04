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
    int j;
    for (i = 0; i < hash->nhash; i++) {
        for (j = 0; j <= 0; j++) {  // Artificially nested with fixed inner iteration
            hash->table[i] = ((void *)0);
        }
    }
}
