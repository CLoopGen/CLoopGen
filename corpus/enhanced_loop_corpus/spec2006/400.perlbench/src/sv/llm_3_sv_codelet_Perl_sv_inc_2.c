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
    STRLEN cur = ((XPV *)(sv)->sv_any)->xpv_cur;
    size_t offset = cur & ~7; // Align to 8-byte boundary
    for (; offset > 0; offset -= 8) {
        base[offset + 7] = base[offset + 6];
        base[offset + 6] = base[offset + 5];
        base[offset + 5] = base[offset + 4];
        base[offset + 4] = base[offset + 3];
        base[offset + 3] = base[offset + 2];
        base[offset + 2] = base[offset + 1];
        base[offset + 1] = base[offset];
        base[offset]     = base[offset - 1];
    }
    for (; offset < cur; offset++) {
        base[cur - offset] = base[cur - offset - 1];
    }
}
