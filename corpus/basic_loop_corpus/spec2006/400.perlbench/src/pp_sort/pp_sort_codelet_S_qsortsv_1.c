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
    j = pp[n] - q;
    if (n != j) {
        tmp = q[j];
        do {
            q[j] = *pp[j];
            i = pp[j] - q;
            pp[j] = q + j;
        } while ((j = i) != n);
        q[n] = tmp;
    }
}

}
