#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rlen = 0;
    const char *ptr = aseq;
    for (; *ptr; ptr++) {
        char c = *ptr;
        int is_valid = !(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~');
        temp_rlen += is_valid;
    }
    rlen = temp_rlen;
}
