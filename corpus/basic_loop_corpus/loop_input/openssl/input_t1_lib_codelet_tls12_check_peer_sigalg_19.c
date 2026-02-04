#include <stdint.h>
#include <stdlib.h>

uint16_t sig = 0xABCD;

size_t sent_sigslen = 65536; // ~128KB of data (65536 * 2 bytes)

uint16_t *sent_sigs;

size_t i;

void init_vars() {
    sent_sigs = malloc(sent_sigslen * sizeof(uint16_t));
    if (!sent_sigs) exit(1);

    for (size_t idx = 0; idx < sent_sigslen; idx++) {
        sent_sigs[idx] = (uint16_t)(0xFFFF - idx);
    }

    sig = 0xFFFF - sent_sigslen + 1;
    i = 0;
}