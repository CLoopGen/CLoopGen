#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;

typedef int I32;

typedef size_t STRLEN;

struct xpv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
};

typedef struct xpv XPV;

SV **sp;
I32 i;
I32 j;
I32 maxlen;

#define SP_SIZE 4

static SV* sv_pool;
static XPV* xpv_pool;
static char** pv_storage;

void init_vars() {
    sv_pool = calloc(SP_SIZE, sizeof(SV));
    xpv_pool = calloc(SP_SIZE, sizeof(XPV));
    pv_storage = malloc(SP_SIZE * sizeof(char*));

    for (int idx = 0; idx < SP_SIZE; idx++) {
        pv_storage[idx] = malloc(1); // minimal allocation to avoid NULL deref
        pv_storage[idx][0] = '\0';
        xpv_pool[idx].xpv_pv = pv_storage[idx];
        xpv_pool[idx].xpv_cur = (idx == 1 || idx == 2 || idx == 3) ? (100 * idx) : 0;
        xpv_pool[idx].xpv_len = xpv_pool[idx].xpv_cur;
        sv_pool[idx].sv_any = &xpv_pool[idx];
        sv_pool[idx].sv_refcnt = 1;
        sv_pool[idx].sv_flags = (idx >= 1 && idx <= 3) ? 262144 : 0; // set flag only for indices 1,2,3
    }

    sp = malloc(SP_SIZE * sizeof(SV*));
    for (int idx = 0; idx < SP_SIZE; idx++) {
        sp[idx] = &sv_pool[idx];
    }

    i = 0;
    j = 0;
    maxlen = 0;
}