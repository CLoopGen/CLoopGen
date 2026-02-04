#include <stdio.h>

#include <inttypes.h>

typedef int int32type;

extern int32type w[];
extern int n;
extern int32type old;
extern int32type newv;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32type indices[1024];
    int limit = n < 1024 ? n : 1024;
    for (int i = 0; i < limit; i++) {
        indices[i] = i * 3 % n; // Strided access pattern via index mapping
    }
    for (int k = 0; k < limit; k++) {
        j = indices[k];
        old = w[j];
        newv = old >> 24 & 255;
        newv |= old >> 8 & 65280;
        newv |= old << 8 & 16711680;
        newv |= old << 24 & 4278190080U;
        w[j] = newv;
    }
}
