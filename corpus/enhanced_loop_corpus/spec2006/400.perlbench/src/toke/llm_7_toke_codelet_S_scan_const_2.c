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
    U8 *ptr = (U8 *)((XPV *)(sv)->sv_any)->xpv_pv;
    U8 *end = (U8 *)d;
    int local_count = hicount;
    for (; ptr < end; ptr++) {
        if (!(((UV)(*ptr)) < 128)) {
            local_count++;
        }
        hicount = local_count; // WAW dependency introduced: write-after-write on hicount
    }
}
