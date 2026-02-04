#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FFFILE {
    size_t buf_size;
    unsigned char *buf;
    unsigned char *rpos;
    unsigned char *rend;
    unsigned char *shend;
    ptrdiff_t shlim;
    ptrdiff_t shcnt;
    void *cookie;
    size_t (*read)(struct FFFILE *, unsigned char *, size_t);
} FFFILE;

extern FFFILE *f;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t local_shcnt = f->shcnt;
    for (; i > 3; i--, local_shcnt++) {
        if (f->shend) {
            f->rpos--;
        }
        f->shcnt = local_shcnt; // Introduce WAW dependency on shcnt, resolved inside loop
    }
}
