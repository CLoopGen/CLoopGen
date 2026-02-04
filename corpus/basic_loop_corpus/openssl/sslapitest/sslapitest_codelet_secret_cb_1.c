#include <stdio.h>

#include <inttypes.h>

extern int *secret_len;
extern int i;
extern unsigned char *secret;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < *secret_len; i++)
    secret[i] = 255;

}
