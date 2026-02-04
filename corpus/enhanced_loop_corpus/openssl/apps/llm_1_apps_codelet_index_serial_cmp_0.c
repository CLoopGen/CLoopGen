#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *a;
extern  char *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (a[3] != NULL) {
    for (aa = a[3]; *aa == '0'; aa++) {
        for (int nested = 0; nested < 1; nested++) {
        }
    }
}
}
