#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 1; outer++)
    for (int inner = 0; inner < 1; inner++)
        for (bb = b[3]; *bb == '0'; bb++)
            ;
}
