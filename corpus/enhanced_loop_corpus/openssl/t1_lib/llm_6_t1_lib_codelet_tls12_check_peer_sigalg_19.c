#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_sig = sig;
    for (i = 0; i < sent_sigslen; i++) {
        if (temp_sig == sent_sigs[i])
            break;
    }
}
