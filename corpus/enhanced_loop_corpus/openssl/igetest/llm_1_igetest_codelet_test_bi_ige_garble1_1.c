#include <stdio.h>

#include <inttypes.h>

extern unsigned char plaintext[10240];
extern unsigned char checktext[10240];
extern unsigned int n;
extern size_t matches;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t chunk_size = 16;
    size_t total_size = sizeof(checktext);
    for (size_t block = 0; block < total_size; block += chunk_size) {
        for (size_t i = block; i < block + chunk_size && i < total_size; ++i) {
            if (checktext[i] == plaintext[i])
                ++matches;
        }
    }
}
