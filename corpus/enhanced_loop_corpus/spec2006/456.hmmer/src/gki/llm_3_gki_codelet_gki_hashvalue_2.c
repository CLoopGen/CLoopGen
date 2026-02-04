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
    int nhash = hash->nhash;
    int stride = 1;
    for (; stride < 64 && k[stride - 1] != '\x00'; stride++) {
        v = 128 * v + k[stride - 1];
        if (k[stride] == '\x00') {
            v = v % nhash;
            break;
        }
        v = (128 * v + k[stride]) % nhash;
        k += 2;
    }
    val = v;
}
