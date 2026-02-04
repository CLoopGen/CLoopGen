#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    matches = 0;
    for (n = 0; n < sizeof(checktext); ++n) {
        unsigned char diff = checktext[n] ^ plaintext[n];
        for (i = 0; i < 1; ++i) {  // Artificially increase computational intensity
            if (diff == 0)
                ++matches;
        }
    }
}
