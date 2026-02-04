#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned int U32;
typedef size_t STRLEN;
typedef long IV;
typedef double NV;
typedef int I32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;

struct xpviv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
    IV xiv_iv;
};

typedef struct xpviv XPVIV;

struct xpvnv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
    IV xiv_iv;
    NV xnv_nv;
};

typedef struct xpvnv XPVNV;

U32 PL_cop_seqmax = 1000000;
SV PL_sv_undef;
I32 PL_min_intro_pending = 0;
I32 PL_max_intro_pending = 131072; // ~131k iterations to target ~0.01s runtime
SV **svp;

SV *sv;
I32 i;

void init_vars() {
    const size_t num_svs = PL_max_intro_pending + 1;
    svp = (SV**)calloc(num_svs, sizeof(SV*));
    if (!svp) exit(1);

    for (size_t idx = 0; idx < num_svs; idx++) {
        SV *new_sv = (SV*)calloc(1, sizeof(SV));
        if (!new_sv) exit(1);

        XPVIV *xpiv = (XPVIV*)calloc(1, sizeof(XPVIV));
        if (!xpiv) exit(1);

        XPVNV *xpnv = (XPVNV*)calloc(1, sizeof(XPVNV));
        memcpy(xpnv, xpiv, sizeof(XPVIV));

        new_sv->sv_any = xpiv;
        new_sv->sv_flags = 0;

        if (idx % 2 == 0) {
            new_sv->sv_refcnt = 1;
            xpiv->xiv_iv = 0;
            svp[idx] = new_sv;
        } else {
            new_sv->sv_refcnt = 0;
            xpiv->xiv_iv = 1;
            svp[idx] = new_sv;
        }
    }

    PL_sv_undef.sv_any = NULL;
    PL_sv_undef.sv_refcnt = 0;
    PL_sv_undef.sv_flags = 0;
}