#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPENSSL_STRING temp[6];
    for (i = 0; i < 6; i++) {
        temp[i] = ((void *)0);
    }
    for (i = 0; i < 6; i++) {
        row[i] = temp[i];
    }
}
