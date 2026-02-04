#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < (6 + 3); i++) {
        temp += *xi;      // Introduce RAW dependency: read before write
        *xi++ = temp;     // WAW and WAR dependencies introduced via reuse of *xi and temp
        temp ^= 1;        // Loop-carried dependency on temp across iterations
    }
}
