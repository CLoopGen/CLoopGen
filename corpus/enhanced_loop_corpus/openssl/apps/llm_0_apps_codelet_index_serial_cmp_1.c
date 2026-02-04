#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1; i++) {
    for (bb = b[3]; *bb == '0'; bb++)
        ;
}
}
