#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

typedef SV *gptr;

extern size_t nmemb;
extern gptr **pp;
extern gptr *q;
extern size_t n;
extern size_t j;
extern size_t i;
extern gptr tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reverse traversal and direct indexing
    for (n = nmemb; n--;) {
        j = pp[n] - q;
        if (n != j) {
            tmp = q[j];
            // Unroll the chain movement using a counted loop instead of do-while
            for (i = j; i != n; ) {
                q[i] = *pp[i];
                size_t next_i = pp[i] - q;
                pp[i] = q + i;
                i = next_i;
            }
            q[n] = tmp;
        }
    }
}
