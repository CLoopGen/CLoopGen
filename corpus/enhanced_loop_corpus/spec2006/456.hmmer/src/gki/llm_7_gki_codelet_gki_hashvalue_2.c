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
    int iter_val = val;
    char *ptr = key;
    for (; ptr[0] != '\x00' && ptr[1] != '\x00'; ptr += 2) {
        int first_step = 128 * iter_val + ptr[0];
        int second_step = 128 * first_step + ptr[1];
        iter_val = second_step % hash->nhash;
    }
    for (; *ptr != '\x00'; ptr++) {
        iter_val = 128 * iter_val + *ptr;
        if (*(++ptr) == '\x00') {
            iter_val = iter_val % hash->nhash;
            break;
        }
        iter_val = (128 * iter_val + *ptr) % hash->nhash;
    }
    val = iter_val;
}
