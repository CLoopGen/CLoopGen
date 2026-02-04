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
    int n = hash->nhash;
    for (i = 0; i < n; i += 2) {
        if (i < n) hash->table[i] = ((void *)0);
        if (i + 1 < n) hash->table[i + 1] = ((void *)0);
    }
}
