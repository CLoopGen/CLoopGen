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
    ptrdiff_t *access_pattern = (ptrdiff_t []){1, 2, 3, 4};
    size_t pattern_size = 4;
    for (size_t idx = 0; i > 3 && idx < pattern_size; i--, idx++)
        ((f)->shend ? (void)(f)->rpos[-access_pattern[idx]] : (void)0);
}
