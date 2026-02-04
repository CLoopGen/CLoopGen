#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len && !buf[i]; ++i)
    continue;

}
