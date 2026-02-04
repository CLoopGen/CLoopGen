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
    char *temp_cp = cp;
    for (i = 0; i < limit; i++) {
        temp_cp[stride] = temp_cp[stride] - temp_cp[0];
        temp_cp--;
    }
    cp = temp_cp;
}
