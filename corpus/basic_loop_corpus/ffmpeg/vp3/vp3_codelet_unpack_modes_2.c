#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int custom_mode_alphabet[8];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 8; i++)
    custom_mode_alphabet[i] = 0;

}
