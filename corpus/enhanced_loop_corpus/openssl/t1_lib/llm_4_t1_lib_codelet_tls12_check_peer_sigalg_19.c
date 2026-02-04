#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sent_sigslen && sig != *sent_sigs; i++, sent_sigs++) {
        // Control dependency simplified: condition merged into loop guard
        // Loop continues only if sig is not found
    }
}
