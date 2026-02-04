#include <stdio.h>

#include <inttypes.h>

typedef struct evp_md_st EVP_MD;

struct dane_ctx_st {
    const EVP_MD **mdevp;
    uint8_t *mdord;
    uint8_t mdmax;
    unsigned long flags;
};


extern struct dane_ctx_st *dctx;
extern uint8_t mtype;
extern int i;
extern  EVP_MD **mdevp;
extern uint8_t *mdord;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = dctx->mdmax + 1;
    int end = mtype;
    for (i = start; i < end && i < 256; ++i) {
        mdevp[i] = ((void *)0);
        mdord[i] = 0;
        mdevp[i+1] = ((void *)0);
        mdord[i+1] = 0;
        i++;
    }
}
