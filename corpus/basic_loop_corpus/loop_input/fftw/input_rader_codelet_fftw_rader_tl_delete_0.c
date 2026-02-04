#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

typedef struct rader_tls rader_tl;

struct rader_tls {
    INT k1;
    INT k2;
    INT k3;
    R *W;
    int refcnt;
    rader_tl *cdr;
};

R *W;
rader_tl **tl;
rader_tl **tp;
rader_tl *t;

void init_vars() {
    const size_t num_elements = 1000000 / sizeof(R);
    W = (R*)aligned_alloc(_Alignof(R), num_elements * sizeof(R));
    if (!W) exit(1);

    tl = (rader_tl**)aligned_alloc(_Alignof(rader_tl*), 256 * sizeof(rader_tl*));
    if (!tl) exit(1);

    rader_tl* list = (rader_tl*)aligned_alloc(_Alignof(rader_tl), 256 * sizeof(rader_tl));
    if (!list) exit(1);

    for (int i = 0; i < 255; i++) {
        tl[i] = &list[i];
        list[i].W = (R*)(i == 254 ? NULL : &W[1]); 
        list[i].cdr = &list[i + 1];
        list[i].refcnt = 1;
        list[i].k1 = i;
        list[i].k2 = i + 1;
        list[i].k3 = i + 2;
    }

    list[255 - 1].W = &W[0]; 
    list[255 - 1].cdr = NULL;
    list[255 - 1].refcnt = 1;
    list[255 - 1].k1 = 255;
    list[255 - 1].k2 = 256;
    list[255 - 1].k3 = 257;

    tl[255] = &list[255 - 1];

    tp = tl;
    t = *tp;
}