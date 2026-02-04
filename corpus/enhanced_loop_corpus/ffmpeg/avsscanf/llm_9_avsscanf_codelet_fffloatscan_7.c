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
    ptrdiff_t limit = (ptrdiff_t)(i - 3);
    for (size_t j = 0; j < limit; j += 1) {
        f->shcnt += (j % 4 == 0) ? 1 : 0;
        if (f->shend && f->rpos > f->buf) {
            (void)--(f->rpos);
        }
    }
    i = 3;
}
