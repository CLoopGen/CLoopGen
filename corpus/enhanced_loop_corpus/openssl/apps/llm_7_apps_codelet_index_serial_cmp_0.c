#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *a;
extern  char *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **ptr = &aa;
    for (*ptr = a[3]; **ptr == '0'; (*ptr)++) {
        if (**ptr != '0') break;
    }
}
