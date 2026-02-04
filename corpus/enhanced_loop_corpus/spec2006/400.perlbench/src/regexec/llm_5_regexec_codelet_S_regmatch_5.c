#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef unsigned int U32;

extern I32 *PL_regendp;
extern U32 *PL_reglastparen;
extern I32 n;
extern I32 lastparen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = *PL_reglastparen; n > lastparen; n--) {
        if (n % 2 == 0) {
            continue;
        }
        PL_regendp[n] = -1;
    }
}
