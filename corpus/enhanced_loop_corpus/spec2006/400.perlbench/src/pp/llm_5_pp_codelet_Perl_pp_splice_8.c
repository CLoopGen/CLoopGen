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
    for (i = offset; i > 0; i--) {
        if (*src == NULL)
            continue;
        *dst-- = *src--;
    }
}
