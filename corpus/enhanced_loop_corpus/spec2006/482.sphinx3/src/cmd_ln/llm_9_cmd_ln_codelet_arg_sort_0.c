#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *pos;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (i = 0; i < n; i++) {
        pos[i] = i * i - 2 * i + 1; // (i-1)^2 expressed as polynomial
        for (j = 0; j < 3; j++) {
            pos[i] += j;
        }
    }
}
