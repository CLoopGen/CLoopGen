#include <stdio.h>

#include <inttypes.h>

extern  char *out;
extern size_t outl;
extern size_t i;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '\x00';
    for (i = 0, c = '\x00'; i < outl; i++) {
        char temp = out[i];
        c = (prev == '\x00' || prev == '\n') ? temp : c;
        prev = temp;
        if (temp == '\n') break;
    }
}
