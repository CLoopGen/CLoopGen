#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *idx = inserts;
    int limit = mlen + 1;
    for (k = 0; k < limit; k++) {
        if (*(idx + k) > 1)
            *(idx + k) = 1;
    }
}
