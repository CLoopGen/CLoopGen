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
    size_t i;
    for (n = nmemb, pp = indir, q = list1; n--;)
        for (i = 1; i > 0; i--)
            *pp++ = q++;
}
