#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *active;
extern int32 i;
extern int32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; active[i] >= 0; i++) {
    if (active[i] < 0) {
        break;
    }
    c = active[i];
}
}
