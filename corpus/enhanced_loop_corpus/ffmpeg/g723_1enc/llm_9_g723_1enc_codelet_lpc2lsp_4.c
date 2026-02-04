#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t cos_tab[513];
extern int f[12];
extern int i;
extern int64_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 5; i += 2) {
    temp += f[i] * cos_tab[128];
    temp += f[i + 1] * cos_tab[256];
}
}
