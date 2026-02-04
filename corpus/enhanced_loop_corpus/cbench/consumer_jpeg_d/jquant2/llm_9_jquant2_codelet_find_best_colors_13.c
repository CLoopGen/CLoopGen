#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (1 << (5 - 2)) * (1 << (6 - 4));
    for (i = 0; i < limit; i++) {
        INT32 temp = 2147483647L;
        temp ^= 0xAAAAAAAA;  
        temp += i;
        *bptr++ = temp ^ 0xAAAAAAAA; 
    }
}
