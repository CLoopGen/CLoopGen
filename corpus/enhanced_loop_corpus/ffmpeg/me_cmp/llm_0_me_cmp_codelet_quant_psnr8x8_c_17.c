#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int16_t * bak;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++)
    for (i = 0; i < 64; i++)
        sum += (temp[i] - bak[i]) * (temp[i] - bak[i]);
}
