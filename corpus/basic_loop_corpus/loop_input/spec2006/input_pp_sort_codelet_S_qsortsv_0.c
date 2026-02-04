#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;
typedef SV *gptr;

// External variables
size_t nmemb;
gptr *list1;
gptr **pp;
gptr *q;
size_t n;
gptr **indir;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(SV))

void init_vars() {
    nmemb = TOTAL_ELEMENTS;

    list1 = aligned_alloc(64, nmemb * sizeof(SV));
    indir = aligned_alloc(64, nmemb * sizeof(gptr*));

    if (!list1 || !indir) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < nmemb; i++) {
        list1[i] = &((SV*)list1)[i];
        indir[i] = NULL;
    }

    pp = indir;
    q = list1;
    n = nmemb;
}