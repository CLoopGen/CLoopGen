#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (codes == 0) return;
    for (sym = 0; sym < codes; sym++) {
        unsigned short len = lens[sym];
        if (len < 16) {
            count[len]++;
        }
    }
}
