#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; runlength > 0; runlength--) {
    *q++ = (*mark);
    mark += 4;
}

}
