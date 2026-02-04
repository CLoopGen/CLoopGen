#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i, j;
    matches = 0;
    for (i = 0; i < sizeof(checktext); i += 2) {
        for (j = i; j < i + 2 && j < sizeof(checktext); ++j) {
            if (checktext[j] == plaintext[j])
                ++matches;
        }
    }
}
