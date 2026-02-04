#include <stdio.h>

#include <inttypes.h>

typedef char *OPENSSL_STRING;

extern int i;
extern OPENSSL_STRING row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 6; i++)
            row[i] = ((void *)0);
}
