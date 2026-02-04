#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

SV *sv;
char *d;

static char *data_buffer;
static XPV *xpv_ptr;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    data_buffer = (char *)calloc(data_size + 1, sizeof(char));
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize data with some pattern to avoid all zeros
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (char)(i & 0xFF);
    }

    xpv_ptr = (XPV *)malloc(sizeof(XPV));
    if (!xpv_ptr) {
        fprintf(stderr, "Failed to allocate XPV\n");
        exit(1);
    }

    xpv_ptr->xpv_pv = data_buffer;
    xpv_ptr->xpv_cur = data_size; // point to last valid index
    xpv_ptr->xpv_len = data_size;

    sv = (SV *)malloc(sizeof(SV));
    if (!sv) {
        fprintf(stderr, "Failed to allocate SV\n");
        exit(1);
    }

    sv->sv_any = xpv_ptr;
    sv->sv_refcnt = 1;
    sv->sv_flags = 0;

    d = xpv_ptr->xpv_pv + xpv_ptr->xpv_cur;
}