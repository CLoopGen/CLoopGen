#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i <= mlen; i++) {
        for (k = i; k <= i; k++) {
            inserts[k] = 0;
        }
    }
}
