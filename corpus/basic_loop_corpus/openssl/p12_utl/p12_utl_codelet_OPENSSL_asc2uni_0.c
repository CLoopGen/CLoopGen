#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < ulen - 2; i += 2) {
    unitmp[i] = 0;
    unitmp[i + 1] = asc[i >> 1];
}

}
