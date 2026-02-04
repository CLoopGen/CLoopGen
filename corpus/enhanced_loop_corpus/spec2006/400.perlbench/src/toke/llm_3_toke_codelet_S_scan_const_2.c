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
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    U8 *base = (U8 *)((XPV *)(sv)->sv_any)->xpv_pv;
    U8 *limit = (U8 *)d;
    size_t length = limit - base;
    // Simulate an indirect access pattern by traversing in reverse order (indirect-like pattern)
    for (size_t i = 0; i < length; i++) {
        U8 *c_ptr = base + (length - 1 - i); // Reverse traversal as form of altered access
        if (!(((UV)(*c_ptr)) < 128)) {
            hicount++;
        }
    }
    // Update c to reflect the final expected state (past-the-end)
    c = limit;
}
