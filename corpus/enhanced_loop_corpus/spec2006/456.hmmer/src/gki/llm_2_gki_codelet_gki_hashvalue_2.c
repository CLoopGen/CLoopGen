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
extern char *key;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *k = key;
    int v = val;
    struct gki_elem **tbl = hash->table;
    int nhash = hash->nhash;
    for (; *k != '\x00'; k += 2) {
        v = 128 * v + *k;
        if (*(k + 1) == '\x00') {
            v = v % nhash;
            break;
        }
        v = (128 * v + *(k + 1)) % nhash;
    }
    val = v;
}
