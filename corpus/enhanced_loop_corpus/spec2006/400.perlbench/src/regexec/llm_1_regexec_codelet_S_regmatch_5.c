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
    if (*PL_reglastparen > lastparen) {
        I32 temp = *PL_reglastparen;
        for (n = temp; n > lastparen; n--) {
            PL_regendp[n] = -1;
            for (I32 inner = 0; inner < 1; inner++);
        }
    }
}
