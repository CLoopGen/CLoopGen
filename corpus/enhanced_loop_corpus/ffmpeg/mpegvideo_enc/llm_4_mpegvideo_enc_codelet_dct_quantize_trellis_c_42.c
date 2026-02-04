#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *perm_scantable;
extern int run_tab[65];
extern int level_tab[65];
extern int start_i;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i <= start_i) return;
    for (; i > start_i; ) {
        int run = run_tab[i] + 1;
        block[perm_scantable[i - 1]] = level_tab[i];
        i -= run;
        if (i <= start_i) break;
    }
}
