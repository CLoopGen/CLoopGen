#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long long padlen;
extern  char *ch;
extern char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (padlen > 0) {
        for (long long j = 0; j < 1; j++) {
            for (long long i = 0; i < padlen; i++) {
                buf[i] = *ch;
            }
        }
    }
}
