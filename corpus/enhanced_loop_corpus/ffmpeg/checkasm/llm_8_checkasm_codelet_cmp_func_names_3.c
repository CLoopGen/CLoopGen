#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int diff = 0;
    const unsigned char *pa = (const unsigned char *)a;
    const unsigned char *pb = (const unsigned char *)b;
    while (*pa && *pb) {
        diff = *pa - *pb;
        if (diff) {
            ascii_diff = diff;
            break;
        }
        pa++;
        pb++;
    }
    if (!*pa || !*pb) ascii_diff = *pa - *pb;
    a = (char*)pa;
    b = (char*)pb;
}
