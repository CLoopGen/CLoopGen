#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (p += 3; p < end && *p == 255; p++)
    ;

}
