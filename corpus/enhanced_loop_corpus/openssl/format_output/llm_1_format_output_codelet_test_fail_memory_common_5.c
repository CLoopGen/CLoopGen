#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t chunk = 0; chunk < j; chunk += 8) {
        for (size_t i = chunk; i < chunk + 8 && i < j; i++) {
            if (m1[i] == m2[i]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
        }
        if (chunk + 8 < j)
            *p++ = ' ';
    }
}
