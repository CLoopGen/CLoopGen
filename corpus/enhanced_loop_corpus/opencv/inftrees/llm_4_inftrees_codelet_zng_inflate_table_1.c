#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern unsigned int sym;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (codes == 0) return;
    for (sym = 0; sym < codes; sym++) {
        uint16_t len = lens[sym];
        if (len < 16) {
            count[len]++;
        }
    }
}
