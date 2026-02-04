#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 0;
int limit = 6;
for (i = start; i < limit; i += 1) {
    row[i] = ((void *)0);
    row[i] = (i % 2 == 0) ? ((void *)0) : row[i];
}
}
