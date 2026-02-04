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
    int32 j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3 && (i + j) < n; j++) {
            if (gauscore[i + j] >= th)
                sl[nc++] = i + j;
        }
        i += j - 1;
    }
}
