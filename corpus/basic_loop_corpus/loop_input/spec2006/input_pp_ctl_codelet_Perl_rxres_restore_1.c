#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long UV;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};

typedef struct regnode regnode;

struct reg_substr_data {
    // Placeholder structure
    void *data;
};

struct reg_data {
    // Placeholder structure
    void *data;
};

struct regexp {
    I32 *startp;
    I32 *endp;
    regnode *regstclass;
    struct reg_substr_data *substrs;
    char *precomp;
    struct reg_data *data;
    char *subbeg;
    U32 *offsets;
    I32 sublen;
    I32 refcnt;
    I32 minlen;
    I32 prelen;
    U32 nparens;
    U32 lastparen;
    U32 lastcloseparen;
    U32 reganch;
    regnode program[1];
};

typedef struct regexp REGEXP;

REGEXP *rx;
UV *p;
U32 i;

static I32 *startp_data;
static I32 *endp_data;
static UV *uv_data;
static REGEXP rx_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data for ~0.01 sec runtime
    const U32 max_nparens = (data_size / sizeof(UV)) / 2; // Each iteration consumes 2 UVs

    // Allocate buffers
    startp_data = (I32*)calloc(max_nparens + 1, sizeof(I32));
    endp_data = (I32*)calloc(max_nparens + 1, sizeof(I32));
    uv_data = (UV*)malloc(data_size);
    
    if (!startp_data || !endp_data || !uv_data) {
        exit(1);
    }

    // Initialize UV data with dummy values
    for (size_t j = 0; j < (data_size / sizeof(UV)); ++j) {
        uv_data[j] = j;
    }

    // Initialize rx_storage
    memset(&rx_storage, 0, sizeof(rx_storage));
    rx_storage.startp = startp_data;
    rx_storage.endp = endp_data;
    rx_storage.nparens = max_nparens;
    rx_storage.refcnt = 1;
    rx_storage.minlen = 1;
    rx_storage.prelen = 1;
    rx_storage.lastparen = 0;
    rx_storage.lastcloseparen = 0;
    rx_storage.reganch = 0;

    // Set external pointers
    rx = &rx_storage;
    p = uv_data;
}