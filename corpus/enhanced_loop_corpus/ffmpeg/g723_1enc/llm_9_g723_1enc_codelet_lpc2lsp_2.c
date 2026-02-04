#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int f[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (10 / 2) * 2; i += 2) {
        int j = i >> 1;
        f[i + 2] = -f[i] - ((lsp[j] + lsp[9 - j]) << 12);
        f[i + 3] = f[i + 1] - ((lsp[j] - lsp[9 - j]) << 12);
    }
}
