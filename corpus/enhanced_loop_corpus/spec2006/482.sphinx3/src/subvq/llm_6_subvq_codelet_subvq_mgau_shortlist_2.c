#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *gauscore;
extern int32 i;
extern int32 th;
extern int32 nc;
extern int32 *sl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_nc = 0;
    for (i = 0; i < n; i++) {
        if (gauscore[i] >= th) {
            sl[local_nc] = i;
            local_nc++;
        }
    }
    nc += local_nc;
}
