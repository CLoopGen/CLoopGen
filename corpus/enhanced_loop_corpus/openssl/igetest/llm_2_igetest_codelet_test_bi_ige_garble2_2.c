#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    matches = 0;
    for (n = 0; n < sizeof(checktext); n += 4) {
        if (checktext[n] == plaintext[n])
            ++matches;
        if (n + 1 < sizeof(checktext) && checktext[n + 1] == plaintext[n + 1])
            ++matches;
        if (n + 2 < sizeof(checktext) && checktext[n + 2] == plaintext[n + 2])
            ++matches;
        if (n + 3 < sizeof(checktext) && checktext[n + 3] == plaintext[n + 3])
            ++matches;
    }
}
