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
    int temp_val = val;
    for (; *key != '\x00'; key += 2) {
        temp_val = 128 * temp_val + *key;
        if (*(key + 1) == '\x00') {
            temp_val %= hash->nhash;
            break;
        }
        temp_val = 128 * temp_val + *(key + 1);
        temp_val %= hash->nhash;
    }
    val = temp_val;
}
