#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long long padlen;
extern  char *ch;
extern char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char temp = *ch;
    for (long long j = 0; j < padlen; j++) {
        buf[j] = temp;
    }
}
