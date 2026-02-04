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
    for (int j = hash->nhash - 1; j >= 0; j--) {
        hash->table[j] = ((void *)0);
        if (j > 0) {
            hash->table[j-1] = ((void *)0); // Introduces WAW dependency and loop-carried dependence
            j--; // Skip next iteration to avoid overwriting, simulating a block write effect
        }
    }
}
