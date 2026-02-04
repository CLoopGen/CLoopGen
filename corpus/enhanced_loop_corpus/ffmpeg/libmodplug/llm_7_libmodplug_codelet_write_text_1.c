#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_char = 0;
    for (i = 0; s[i]; i++, dst += 3) {
        dst[0] = prev_char;        
        dst[1] = s[i];             
        dst[2] = s[i] ^ prev_char;  
        prev_char = s[i];           
    }
}
