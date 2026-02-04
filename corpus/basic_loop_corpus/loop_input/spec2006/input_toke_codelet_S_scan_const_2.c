#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int U32;
typedef unsigned char U8;
typedef size_t STRLEN;
typedef unsigned long UV;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

struct xpv {
    char *xpv_pv;
    STRLEN xpv_cur;
    STRLEN xpv_len;
};

typedef struct sv SV;
typedef struct xpv XPV;

SV *sv;
char *d;
int hicount;
U8 *c;

#define DATA_SIZE (128 << 20)  // 128 MB

static char *data_buffer = NULL;
static XPV *xpv_struct = NULL;

void init_vars() {
    data_buffer = (char *)malloc(DATA_SIZE);
    if (!data_buffer) {
        exit(1);
    }

    xpv_struct = (XPV *)malloc(sizeof(XPV));
    if (!xpv_struct) {
        free(data_buffer);
        exit(1);
    }

    // Initialize data: mix of ASCII and non-ASCII
    for (size_t i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = (i % 256);
    }

    xpv_struct->xpv_pv = data_buffer;
    xpv_struct->xpv_cur = DATA_SIZE;
    xpv_struct->xpv_len = DATA_SIZE;

    sv = (SV *)malloc(sizeof(SV));
    if (!sv) {
        free(data_buffer);
        free(xpv_struct);
        exit(1);
    }

    sv->sv_any = xpv_struct;
    sv->sv_refcnt = 1;
    sv->sv_flags = 0;

    d = data_buffer + DATA_SIZE;
    hicount = 0;
    c = NULL;
}