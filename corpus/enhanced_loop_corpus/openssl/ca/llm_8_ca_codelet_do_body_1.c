#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];
extern OPENSSL_STRING *irow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        irow[i] = row[i];
        if (i + 1 < 6) {
            irow[i + 1] = row[i + 1];
        }
    }
}
