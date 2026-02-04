#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int f[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1, temp2;
    for (i = 0; i < 10 / 2; i++) {
        temp1 = -f[2 * i] - ((lsp[i] + lsp[10 - 1 - i]) << 12);
        temp2 = f[2 * i + 1] - ((lsp[i] - lsp[10 - 1 - i]) << 12);
        f[2 * i + 2] = temp1;
        f[2 * i + 3] = temp2;
    }
}
