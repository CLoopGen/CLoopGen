#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef struct rader_tls rader_tl;

struct rader_tls {
    INT k1;
    INT k2;
    INT k3;
    R *W;
    int refcnt;
    rader_tl *cdr;
};


extern R *W;
extern rader_tl **tl;
extern rader_tl **tp;
extern rader_tl *t;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern through indirect indexing
    rader_tl **current = tl;
    INT stride = 2; // Access every second element in a conceptual array of pointers
    for (INT i = 0; current[i] != NULL; i += stride) {
        t = current[i];
        if (t->W == W) break;
        if (current[i + 1]) tp = &(current[i + 1]->cdr); // Update tp to next valid link
    }
}
