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
    for (c = start; c < (U8 *)d; c++) {
        for (int unroll = 0; unroll < 1; unroll++) {
            if (!(((UV)(*c)) < 128)) {
                hicount++;
            }
        }
    }
}
