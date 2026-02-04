#include <stdio.h>

#include <inttypes.h>

extern signed char e[64];
extern signed char carry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 62; i += 2) {
    signed char temp1 = e[i] + carry;
    carry = (temp1 + 8) >> 4;
    e[i] = temp1 - (carry << 4);

    signed char temp2 = e[i+1] + carry;
    carry = (temp2 + 8) >> 4;
    e[i+1] = temp2 - (carry << 4);
}
}
