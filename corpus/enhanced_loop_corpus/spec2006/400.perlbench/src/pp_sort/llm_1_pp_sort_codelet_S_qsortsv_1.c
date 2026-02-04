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



void loop(){
    for (n = nmemb; n--;) {
        for (j = pp[n] - q; n != j; ) {
            tmp = q[j];
            for (i = j; i != n; ) {
                q[i] = *pp[i];
                j = pp[i] - q;
                pp[i] = q + i;
                i = j;
            }
            q[n] = tmp;
            break;
        }
    }
}
