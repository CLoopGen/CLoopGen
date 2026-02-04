#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dc_lsp[10];
extern int16_t *cur_lsp;
extern int16_t *prev_lsp;
extern int pred;
extern int i;
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    temp = ((prev_lsp[i] - dc_lsp[i]) * pred + (1 << 13)) >> 14;
    cur_lsp[i] += dc_lsp[i] + temp;
    cur_lsp[9-i] += dc_lsp[9-i] + temp;
}
}
