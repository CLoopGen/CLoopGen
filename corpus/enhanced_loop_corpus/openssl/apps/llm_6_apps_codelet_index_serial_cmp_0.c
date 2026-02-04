#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *a;
extern  char *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = a[3];
    for (aa = temp; *temp == '0'; temp++) {
        aa = temp;
    }
}
