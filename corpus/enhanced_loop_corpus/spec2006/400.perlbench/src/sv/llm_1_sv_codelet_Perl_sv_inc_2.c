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
    char *base = ((XPV *)(sv)->sv_any)->xpv_pv;
    STRLEN len = ((XPV *)(sv)->sv_any)->xpv_cur;
    if (len > 0) {
        for (STRLEN i = len; i > 0; i--) {
            base[i] = base[i - 1];
        }
    }
}
