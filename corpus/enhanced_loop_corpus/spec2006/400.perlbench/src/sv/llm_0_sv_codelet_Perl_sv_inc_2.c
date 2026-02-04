#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

typedef size_t STRLEN;

struct xpv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
};


typedef struct xpv XPV;

extern SV *sv;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *start = ((XPV *)(sv)->sv_any)->xpv_pv;
    char *current = start + ((XPV *)(sv)->sv_any)->xpv_cur;
    for (; current > start; current--) {
        *current = current[-1];
    }
}
