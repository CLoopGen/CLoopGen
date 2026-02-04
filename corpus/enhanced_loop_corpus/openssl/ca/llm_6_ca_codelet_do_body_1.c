#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];
extern OPENSSL_STRING *irow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPENSSL_STRING temp[6];
    for (i = 0; i < 6; i++)
        temp[i] = row[i];
    for (i = 0; i < 6; i++)
        irow[i] = temp[i];
}
