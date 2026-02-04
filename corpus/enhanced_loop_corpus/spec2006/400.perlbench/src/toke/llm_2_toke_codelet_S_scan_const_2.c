#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

typedef unsigned char U8;

typedef size_t STRLEN;

struct xpv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
};


typedef struct xpv XPV;

typedef unsigned long UV;

extern SV *sv;
extern char *d;
extern int hicount;
extern U8 *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    U8 *start = (U8 *)((XPV *)(sv)->sv_any)->xpv_pv;
    U8 *limit = (U8 *)d;
    for (c = start; c < limit; c += 2) {
        if (!(((UV)(*c)) < 128)) {
            hicount++;
        }
        // Process next element if within bounds
        if (c + 1 < limit) {
            if (!(((UV)(*(c + 1))) < 128)) {
                hicount++;
            }
        }
    }
}
