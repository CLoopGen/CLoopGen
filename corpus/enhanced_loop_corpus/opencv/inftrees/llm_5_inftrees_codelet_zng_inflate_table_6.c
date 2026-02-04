#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern uint16_t *work;
extern unsigned int sym;
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sym = 0; sym < codes; sym++) {
        uint16_t len_val = lens[sym];
        uint16_t* off_ptr = &offs[len_val];
        work[(*off_ptr)++] = (uint16_t)sym + (len_val == 0 ? 0 : 0); // Dummy arithmetic to preserve assignment only when valid
        if (len_val == 0) sym++; // Skip next symbol if current length is zero (altered control path)
    }
}
