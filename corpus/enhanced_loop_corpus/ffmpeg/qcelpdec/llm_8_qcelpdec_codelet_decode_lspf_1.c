#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 10; i += 2)
        lspf[i] = (lspf[i] > lspf[i - 1] + 0.04) ? lspf[i] : lspf[i - 1] + 0.04;
}
