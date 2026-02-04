#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced to a single conditional expression using a counted loop with step merge
    // Nesting depth decreased: flat structure with no inner loops or conditionals
    for (i = 0; (i < sent_sigslen) && (sig != *sent_sigs); i++, sent_sigs++)
        ; // Empty body: logic absorbed into loop condition and increment
}
