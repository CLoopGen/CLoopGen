#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    matches = 0;
    for (n = 0; n < sizeof(checktext); ++n) {
        matches += (checktext[n] == plaintext[n]);
    }
}
