#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *a;
extern  char *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (aa = a[3]; *aa == '0' && count < 100; aa++, count++)
        ;
}
