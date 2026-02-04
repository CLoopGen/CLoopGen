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
    size_t temp_i = i;
    for (; temp_i > 3; temp_i--) {
        if (f->shend) {
            f->rpos--;
        }
    }
    i = temp_i;
}
