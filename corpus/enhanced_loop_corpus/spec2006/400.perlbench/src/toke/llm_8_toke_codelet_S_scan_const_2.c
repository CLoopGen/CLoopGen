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
    U8 *start = (U8 *)((XPV *)(sv)->sv_any)->xpv_pv;
    U8 *limit = (U8 *)d;
    for (c = start; c < limit; c += 2) {
        if (c + 1 >= limit) break;
        UV val1 = (UV)(*c);
        UV val2 = (UV)(*(c+1));
        if (!(((val1) < 128) && ((val2) < 128))) {
            hicount += (val1 >= 128) + (val2 >= 128);
        }
    }
    if (c == limit - 1) {
        if (((UV)(*c)) >= 128) hicount++;
    }
}
