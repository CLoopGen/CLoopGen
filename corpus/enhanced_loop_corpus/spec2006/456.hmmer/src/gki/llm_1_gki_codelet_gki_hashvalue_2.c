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



void loop(){
    // Variant 2: Reduced effective nesting by flattening potential inner logic into a single deeper condition
    // This reduces conceptual nesting by eliminating the inner if-break and merging conditions
    for (; *key != '\x00' && *(key+1) != '\x00'; key += 2) {
        val = 128 * val + *key;
        val = (128 * val + *(key+1)) % hash->nhash;
    }
    // Handle case where loop ended with one character left
    if (*key != '\x00') {
        val = 128 * val + *key;
        val = val % hash->nhash;
    }
}
