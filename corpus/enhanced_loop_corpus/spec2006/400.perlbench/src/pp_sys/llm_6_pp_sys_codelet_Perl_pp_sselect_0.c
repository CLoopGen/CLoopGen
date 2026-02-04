#include <stdio.h>

#include <inttypes.h>

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

extern SV **sp;
extern I32 i;
extern I32 j;
extern I32 maxlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp_maxlen = maxlen;
    for (i = 1; i <= 3; i++) {
        if (!((sp[i])->sv_flags & 262144))
            continue;
        j = ((XPV *)(sp[i])->sv_any)->xpv_cur;
        if (temp_maxlen < j)
            temp_maxlen = j;
    }
    maxlen = temp_maxlen;
}
