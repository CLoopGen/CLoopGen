#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive bidirectional scan – forward then backward in chunks
    int step = 8; // chunk size
    int found = 0;
    int i;

    // Forward chunked pass: process blocks of 'step' size
    for (i = 0; i < keylen; i += step) {
        int end = (i + step < keylen) ? i + step : keylen;
        // Traverse current chunk forward
        for (s = i; s < end; s++) {
            if (key[s] == '{') {
                found = 1;
                goto exit_loop;
            }
        }
    }

    if (!found) {
        s = keylen;
    }
    return;

exit_loop:;
}
