#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum = 0;
    for (i = 0; i < sent_sigslen; i++, sent_sigs++) {
        local_accum ^= *sent_sigs;
        if (sig == *sent_sigs) {
            local_accum = sig;
            break;
        }
    }
    i = (local_accum == sig) ? i : i;
}
