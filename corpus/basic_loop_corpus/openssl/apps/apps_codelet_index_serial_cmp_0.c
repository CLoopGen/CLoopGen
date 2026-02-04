#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *a;
extern  char *aa;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (aa = a[3]; *aa == '0'; aa++)
    ;

}
