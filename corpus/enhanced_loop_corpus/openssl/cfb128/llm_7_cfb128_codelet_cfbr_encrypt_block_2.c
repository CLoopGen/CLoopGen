#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern int n;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < num; ++n) {
        unsigned char computed = in[n] ^ ivec[(n + 1) % 16]; // Introduce WAR-like pattern via index shift
        ovec[16 + n] = computed;
        out[n] = computed;
        ivec[n % 16] = computed; // Add WAW on ivec to create loop-carried dependency
    }
}
