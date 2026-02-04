#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < sizeof(checktext); n += 2) {
        if (n + 1 < sizeof(checktext)) {
            if (checktext[n] == plaintext[n])
                ++matches;
            if (checktext[n + 1] == plaintext[n + 1])
                ++matches;
        } else {
            if (checktext[n] == plaintext[n])
                ++matches;
        }
    }
}
