#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 16; n > 3 && addr[n - 1] == 0 && addr[n - 2] == 0 && addr[n - 3] == 0 && addr[n - 4] == 0; n -= 4)
        ;
}
