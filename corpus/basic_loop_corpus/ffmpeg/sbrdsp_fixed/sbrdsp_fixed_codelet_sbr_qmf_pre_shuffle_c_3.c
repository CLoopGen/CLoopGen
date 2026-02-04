#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 1; k < 32; k++) {
    z[64 + 2 * k] = -z[64 - k];
    z[64 + 2 * k + 1] = z[k + 1];
}

}
