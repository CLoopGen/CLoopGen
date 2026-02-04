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
for (i = 0; i <= 10 / 2; i++)
    temp += f[2 * i] * cos_tab[0];

}
