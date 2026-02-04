#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 20; i++ , cookie++)
    *cookie = i;

}
