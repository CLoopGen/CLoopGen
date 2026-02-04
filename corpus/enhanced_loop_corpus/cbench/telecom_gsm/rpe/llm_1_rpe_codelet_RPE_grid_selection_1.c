#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 6; i++) {
        xM[i] = x[Mc + 3 * i];
        xM[i + 7] = x[Mc + 3 * (i + 7)];
    }
    xM[13] = x[Mc + 3 * 13]; // Adjust in case of off-by-one due to split logic
}
