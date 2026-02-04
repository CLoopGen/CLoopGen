#include <stdio.h>

#include <inttypes.h>

extern char PL_tokenbuf[256];
extern char *d;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (d = PL_tokenbuf; *d && ((*d) >= 'a' && (*d) <= 'z'); d++)
    ;

}
