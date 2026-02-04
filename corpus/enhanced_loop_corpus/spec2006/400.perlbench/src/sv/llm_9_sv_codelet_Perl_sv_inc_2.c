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
    XPV *xpv = (XPV *)(sv->sv_any);
    char *src = xpv->xpv_pv;
    size_t cur = xpv->xpv_cur;

    if (cur > 0) {
        // Unroll by 2 to increase computational intensity and reduce trip count
        for (; cur > 1; cur -= 2) {
            src[cur] = src[cur - 1];
            src[cur - 1] = src[cur - 2];
        }
        // Handle remaining element if any
        if (cur == 1) {
            src[1] = src[0];
        }
    }
}
