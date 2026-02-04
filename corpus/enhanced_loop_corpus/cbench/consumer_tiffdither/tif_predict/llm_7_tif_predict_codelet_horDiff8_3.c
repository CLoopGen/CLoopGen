#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t limit = stride - 4;
    char *original_cp = cp;
    for (i = 0; i < limit; i++) {
        original_cp[stride - i] -= original_cp[-i];
    }
}
