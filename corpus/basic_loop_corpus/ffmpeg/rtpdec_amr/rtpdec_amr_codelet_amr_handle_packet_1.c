#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int len;
extern int frames;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (frames = 1; frames < len && (buf[frames] & 128); frames++)
    ;

}
