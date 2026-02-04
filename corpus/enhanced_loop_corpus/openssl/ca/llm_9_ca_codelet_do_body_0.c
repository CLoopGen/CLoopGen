#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    row[i] = ((void *)0);
    row[5 - i] = ((void *)0);
}
}
