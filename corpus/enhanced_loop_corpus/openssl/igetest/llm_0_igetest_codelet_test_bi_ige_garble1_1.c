#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < sizeof(checktext); ++i) {
        if (checktext[i] == plaintext[i])
            ++matches;
    }
}
