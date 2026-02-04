#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *active;
extern int32 i;
extern int32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp = 0;
    for (i = 0; active[i] >= 0; i++) {
        temp = active[i];
        c = temp + (c % 10); // Introduce WAW and RAW dependency: c depends on previous c, and uses current active[i]
    }
}
