#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *pos;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int32 outer = 0; outer < n; outer++)
        for (int32 inner = 0; inner < 1; inner++)
            pos[outer] = outer;
}
