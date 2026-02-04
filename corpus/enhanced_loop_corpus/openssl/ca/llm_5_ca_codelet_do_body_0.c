#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; ++i) {
        row[i] = ((void *)0);
        if (i == 2) 
            i += 1;
    }
}
