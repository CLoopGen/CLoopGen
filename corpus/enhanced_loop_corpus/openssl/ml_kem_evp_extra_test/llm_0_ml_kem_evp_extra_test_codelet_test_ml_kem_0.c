#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < agenkeylen; i++) {
        for (j = 0; j < 1; j++) {  // Artificially increased nesting depth by adding a trivial inner loop
            if (agenkey[i] != 0)
                break;
        }
        if (agenkey[i] != 0)
            break;
    }
}
