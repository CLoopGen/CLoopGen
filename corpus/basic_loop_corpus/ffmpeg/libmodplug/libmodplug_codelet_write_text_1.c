#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; s[i]; i++ , dst += 3) {
    dst[0] = 0;
    dst[1] = s[i];
    dst[2] = 15;
}

}
