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
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        if (gauscore[i] >= th)
            sl[nc++] = i;
        if (gauscore[i+1] >= th)
            sl[nc++] = i+1;
    } else {
        if (gauscore[i] >= th)
            sl[nc++] = i;
    }
}
}
