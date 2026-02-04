#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= m; i += 2) {
        w[i] = 0.10000000000000001;
        if (i + 1 <= m) {
            w[i + 1] = 0.10000000000000001;
        }
    }
}
