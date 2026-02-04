#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *channels;
extern int32_t *cv;
extern unsigned int val;
extern uint32_t c;
extern uint32_t all_ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = all_ch, cv = channels; c; c >>= 2, cv += 2) {
        if (c & 1)
            *cv += val;
        if ((c >> 1) & 1)
            *(cv + 1) += val;
    }
}
