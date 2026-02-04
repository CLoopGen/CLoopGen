#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i += 2) {
        int32 j = i + 1;
        int32 candidate = i;
        if (j < len && val[j] > val[candidate])
            candidate = j;
        if (val[candidate] > val[bi])
            bi = candidate;
    }
    // Handle potential last odd element
    if ((len - 1) % 2 == 0 && val[len - 1] > val[bi])
        bi = len - 1;
}
