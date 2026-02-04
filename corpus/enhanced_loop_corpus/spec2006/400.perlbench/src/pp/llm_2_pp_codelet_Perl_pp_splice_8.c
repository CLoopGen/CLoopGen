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
    // Variant 1: Strided memory access with stride of 2
    for (i = offset; i > 0; i -= 2) {
        *dst-- = *(src - 0);
        *dst-- = *(src - 1);
        src -= 2;
    }
}
