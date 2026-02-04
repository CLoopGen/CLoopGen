#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer i__;
extern integer ic;
extern char subnam[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= 6; i__ += 1) {
    ic = *(unsigned char *)&subnam[i__ - 1] + 0;
    if (ic >= 129) {
        if (ic <= 137 || (ic >= 145 && ic <= 153) || (ic >= 162 && ic <= 169)) {
            char temp = (char)(ic + 64);
            *(unsigned char *)&subnam[i__ - 1] = temp;
        }
    }
}
}
