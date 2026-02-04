#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < sent_sigslen; i += step) {
        if (sig == *sent_sigs)
            break;
        sent_sigs++;
        if (i + 1 < sent_sigslen) {
            sent_sigs++;
        }
    }
}
