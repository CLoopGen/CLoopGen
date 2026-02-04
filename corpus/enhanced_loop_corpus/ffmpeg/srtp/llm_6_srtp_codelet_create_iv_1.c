#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[14];
    for (i = 0; i < 14; i++)
        temp[i] = iv[i] ^ salt[i];
    for (i = 0; i < 14; i++)
        iv[i] = temp[i];
}
