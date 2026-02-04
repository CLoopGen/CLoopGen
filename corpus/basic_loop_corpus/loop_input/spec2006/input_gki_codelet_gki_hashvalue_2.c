#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char *key;
int val;
GKI *hash;

static struct gki_elem **table_mem;
static char *key_data;

void init_vars() {
    const size_t input_size = 1 << 20; // 1MB of input data

    key_data = (char *)calloc(input_size, sizeof(char));
    if (!key_data) exit(1);

    for (size_t i = 0; i < input_size - 1; i++) {
        key_data[i] = (char)(33 + (i % 94)); // printable ASCII
    }
    key_data[input_size - 1] = '\x00'; // null-terminate

    key = key_data;

    val = 0;

    hash = (GKI *)malloc(sizeof(GKI));
    if (!hash) exit(1);

    hash->nhash = 65536;
    hash->primelevel = 0;
    hash->nkeys = 0;

    table_mem = (struct gki_elem **)calloc(hash->nhash, sizeof(struct gki_elem *));
    if (!table_mem) exit(1);
    hash->table = table_mem;
}