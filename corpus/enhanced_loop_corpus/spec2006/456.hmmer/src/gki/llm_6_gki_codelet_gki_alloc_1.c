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
    struct gki_elem **table = hash->table;
    int nhash = hash->nhash;
    for (int j = 0; j < nhash; j++) {
        table[j] = ((void *)0);
    }
}
