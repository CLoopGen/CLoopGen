#include <stdio.h>

#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

extern  OPENSSL_CSTRING *b;
extern  char *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character)
    char *ptr = b[3];
    for (int i = 0; ptr[i] == '0'; i += 2) {
        ptr = ptr + i;
        if (ptr[i] != '0') break;
        bb = ptr + i + 2; // update bb to next expected position
    }
    bb = (bb < ptr) ? ptr : bb; // ensure bb is at correct termination point
}
