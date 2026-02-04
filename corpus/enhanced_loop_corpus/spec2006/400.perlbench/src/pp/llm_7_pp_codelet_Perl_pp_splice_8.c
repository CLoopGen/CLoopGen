#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

typedef int I32;

extern SV **src;
extern SV **dst;
extern I32 i;
extern I32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    SV **local_src = src - offset + 1;
    SV **local_dst = dst - offset + 1;
    for (i = 0; i < offset; i++) {
        local_dst[i] = local_src[i];
    }
    src -= offset;
    dst -= offset;
}
