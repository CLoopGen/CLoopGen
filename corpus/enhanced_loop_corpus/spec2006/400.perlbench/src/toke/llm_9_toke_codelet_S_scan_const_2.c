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
    U8 *base = (U8 *)((XPV *)(sv)->sv_any)->xpv_pv;
    STRLEN len = ((XPV *)(sv)->sv_any)->xpv_cur;
    for (size_t i = 0; i < len; i++) {
        UV ch = base[i];
        hicount += (ch >= 128) ? (ch >> 6) & 1 : 0;
        hicount += (i % 3 == 0) && (ch >= 128);
    }
}
