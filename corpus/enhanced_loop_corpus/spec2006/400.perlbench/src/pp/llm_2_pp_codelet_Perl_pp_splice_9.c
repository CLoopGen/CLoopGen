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
extern I32 after;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (backwards)
    for (i = after; i > 0; i -= 2) {
        dst[0] = src[0];
        dst[-1] = src[-1];
        dst -= 2;
        src -= 2;
    }
    // Handle remaining element if after is odd
    if (i == -1) {
        *dst-- = *src--;
    }
}
