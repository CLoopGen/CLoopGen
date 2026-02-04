#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t (*tab)[2];
extern int size;
extern int a;
extern int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size && !(tab[i][0] == a && tab[i][1] == b); i++)
    ;

}
