#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < sent_sigslen; i++) {
        for (j = 0; j < 1; j++) {  // Artificially increased nesting depth
            if (sig == sent_sigs[i])
                goto exit_loop;
        }
    }
    return;
exit_loop:
    return;
}
