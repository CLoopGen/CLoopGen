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
for (; *key != '\x00'; key++) {
    val = 128 * val + *key;
    if (*(++key) == '\x00') {
        val = val % hash->nhash;
        break;
    }
    val = (128 * val + *key) % hash->nhash;
}

}
