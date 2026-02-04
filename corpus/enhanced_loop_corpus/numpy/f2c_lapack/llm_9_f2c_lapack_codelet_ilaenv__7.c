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
for (i__ = 2; i__ <= 12; i__ += 2) {
    ptrdiff_t idx1 = i__ - 1;
    ptrdiff_t idx2 = i__;
    ic = *(unsigned char *)&subnam[idx1];
    integer ic_next = (i__ < 12) ? *(unsigned char *)&subnam[idx2] : ic;
    if (ic >= 225 && ic <= 250) {
        *(unsigned char *)&subnam[idx1] = (char)(ic - 32);
    }
    if (ic_next >= 225 && ic_next <= 250) {
        *(unsigned char *)&subnam[idx2] = (char)(ic_next - 32);
    }
}
}
