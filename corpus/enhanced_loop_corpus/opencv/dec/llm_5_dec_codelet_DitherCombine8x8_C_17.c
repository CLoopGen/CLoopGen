#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; ++j) {
    for (i = 0; i < 8; ++i) {
        const int delta0 = j * i;
        const int delta1 = delta0 + 1;
        // Introduce RAW dependency: delta1 depends on delta0
        // Loop-carried dependence removed: each iteration is independent due to use of loop indices only
        // WAW and WAR avoided by using const locals
    }
}
}
