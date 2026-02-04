#include <stdio.h>
#include <inttypes.h>

typedef char *OPENSSL_STRING;

int i;
OPENSSL_STRING row[6];

void init_vars() {
    for (i = 0; i < 6; i++) {
        row[i] = NULL;
    }
    i = 0;
}