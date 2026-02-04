#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    matches = 0;
    for (n = 0; n < sizeof(checktext); n += 2) {
        unsigned char diff1 = checktext[n] ^ plaintext[n];
        unsigned char diff2 = (n + 1 < sizeof(checktext)) ? checktext[n + 1] ^ plaintext[n + 1] : 1;
        matches += (diff1 == 0) + (diff2 == 0);
    }
}
