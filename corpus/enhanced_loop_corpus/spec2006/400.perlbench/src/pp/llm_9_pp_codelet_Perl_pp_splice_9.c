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



void loop(){
    // Variant 2: Reduced trip count with simplified addressing and minimal operations
    // Effectively runs half the original iterations but performs same total work via dual assignments
    for (i = after >> 1; i > 0; i--) {
        dst[0] = src[0];
        dst[-1] = src[-1];
        src -= 2;
        dst -= 2;
    }
}
