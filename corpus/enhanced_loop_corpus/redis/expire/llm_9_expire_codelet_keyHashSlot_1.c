#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = keylen - (keylen % 4);
    for (e = s + 1; e < limit; e++) {
        // Unroll the loop by checking multiple elements per iteration
        if (e + 3 < limit) {
            if (key[e] == '}' || key[e+1] == '}' || key[e+2] == '}' || key[e+3] == '}') {
                // Find the first occurrence within the group
                for (int j = 0; j < 4; j++) {
                    if (key[e + j] == '}') {
                        e = e + j;
                        goto exit_loop;
                    }
                }
                e += 3; // Skip ahead
            }
        } else {
            // Handle remaining elements normally
            for (int j = e; j < keylen; j++) {
                if (key[j] == '}') {
                    e = j;
                    goto exit_loop;
                }
            }
            break;
        }
    }
exit_loop:
    return;
}
