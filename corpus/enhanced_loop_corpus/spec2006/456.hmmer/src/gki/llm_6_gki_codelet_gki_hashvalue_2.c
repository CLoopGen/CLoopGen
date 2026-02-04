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
    char *local_key = key;
    for (; *local_key != '\x00'; ) {
        temp_val = 128 * temp_val + *local_key;
        local_key++;
        if (*local_key == '\x00') {
            temp_val = temp_val % hash->nhash;
            break;
        }
        temp_val = (128 * temp_val + *local_key) % hash->nhash;
        local_key++;
    }
    val = temp_val;
}
