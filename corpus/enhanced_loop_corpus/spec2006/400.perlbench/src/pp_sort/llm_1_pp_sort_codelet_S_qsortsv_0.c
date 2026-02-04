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

extern gptr *list1;
extern size_t nmemb;
extern gptr **pp;
extern gptr *q;
extern size_t n;
extern gptr **indir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer_n;
    for (outer_n = nmemb / 2; outer_n > 0; --outer_n) {
        for (n = 2, pp = &indir[2 * (nmemb / 2 - outer_n)], q = &list1[2 * (nmemb / 2 - outer_n)]; n--;)
            *pp++ = q++;
    }
    if (nmemb % 2) {
        *pp = q;
    }
}
