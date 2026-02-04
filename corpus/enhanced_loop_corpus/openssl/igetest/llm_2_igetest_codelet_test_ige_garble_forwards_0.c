#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    size_t i;
    for (i = 0; i < sizeof(checktext); i += 4) {
        if (checktext[i] == plaintext[i])
            ++matches;
        if (i + 1 < sizeof(checktext) && checktext[i + 1] == plaintext[i + 1])
            ++matches;
        if (i + 2 < sizeof(checktext) && checktext[i + 2] == plaintext[i + 2])
            ++matches;
        if (i + 3 < sizeof(checktext) && checktext[i + 3] == plaintext[i + 3])
            ++matches;
    }
}
