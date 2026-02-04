#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < len; i++) {
    for (int32 j = 0; j < 1; j++) {  // Artificially increased loop depth by adding a trivial inner loop
        if (val[i] > val[bi])
            bi = i;
    }
}
}
