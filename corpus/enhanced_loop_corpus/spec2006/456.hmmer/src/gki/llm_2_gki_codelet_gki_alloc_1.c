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
    int stride = 2;
    int nhash = hash->nhash;
    struct gki_elem **table = hash->table;

    for (i = 0; i < nhash; i += stride)
        table[i] = ((void *)0);

    if (i - stride == nhash - 2) {
        table[nhash - 1] = ((void *)0);
    }
}
