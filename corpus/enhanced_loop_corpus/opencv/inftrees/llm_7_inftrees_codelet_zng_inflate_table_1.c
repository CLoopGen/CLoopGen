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
    count[lens[0]]++;
    for (sym = 1; sym < codes; sym++) {
        uint16_t prev_len = lens[sym - 1];
        uint16_t curr_len = lens[sym];
        count[curr_len]++;
        count[prev_len] += (prev_len == curr_len);
    }
}
