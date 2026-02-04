#include <stdio.h>
#include <stdlib.h>
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

static struct gki_elem **table_data;
GKI *hash;
int i;

void init_vars() {
    hash = (GKI *)calloc(1, sizeof(GKI));
    hash->nhash = 65536;  // Size to target ~0.01s runtime
    hash->primelevel = 0;
    hash->nkeys = 0;
    table_data = (struct gki_elem **)calloc(hash->nhash, sizeof(struct gki_elem *));
    hash->table = table_data;
}