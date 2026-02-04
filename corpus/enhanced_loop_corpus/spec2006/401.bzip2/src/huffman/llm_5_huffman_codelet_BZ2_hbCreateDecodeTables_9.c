#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i++) {
        limit[i] = 0;
        if (i == 22) {
            break;
        }
    }
}
