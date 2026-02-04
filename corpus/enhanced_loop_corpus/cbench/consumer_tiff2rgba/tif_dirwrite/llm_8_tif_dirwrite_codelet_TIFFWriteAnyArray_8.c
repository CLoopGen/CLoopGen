#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef int int32;

extern uint32 n;
extern double *v;
extern int i;
extern int32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (int)n;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            bp[i] = (int32)(v[i] + 1.5);
            bp[i+1] = (int32)(v[i+1] + 1.5);
        } else {
            bp[i] = (int32)(v[i] + 1.5);
        }
    }
}
