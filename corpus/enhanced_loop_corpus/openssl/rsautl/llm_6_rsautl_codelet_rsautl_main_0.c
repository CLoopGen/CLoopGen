#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t left = 0;
    size_t right = rsa_inlen - 1;
    while (left < rsa_inlen / 2) {
        ctmp = rsa_in[left];
        rsa_in[left] = rsa_in[right];
        rsa_in[right] = ctmp;
        left++;
        right--;
    }
}
