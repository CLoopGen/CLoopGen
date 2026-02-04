#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = b[3];
    for (bb = temp; *temp == '0'; temp++) {
        bb = temp;
    }
}
