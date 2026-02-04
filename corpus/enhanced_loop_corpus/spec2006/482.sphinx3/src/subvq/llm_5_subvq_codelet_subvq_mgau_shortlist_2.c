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
for (i = 0; i < n; i++) {
    int32 condition = (gauscore[i] >= th);
    if (condition) {
        sl[nc++] = i;
    } else {
        // Explicitly handle the false case with no-op control flow
        ;
    }
}
}
