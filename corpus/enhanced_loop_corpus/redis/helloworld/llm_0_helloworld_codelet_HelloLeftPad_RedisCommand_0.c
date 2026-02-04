#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long long padlen;
extern  char *ch;
extern char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (long long i = 0; i < padlen; i++) {
        for (long long j = 0; j < 1; j++) {
            buf[i] = *ch;
        }
    }
}
