#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern Hashseq hashprobe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 2, 4, 6, 1, 3, 5, 7};
    int size = sizeof(Hashseq) * 2;
    for (i = 0; i < size; i++) {
        int idx = indices[i % 8] % size;
        hashprobe <<= (4 + (idx & 1));
        hashprobe |= (Hashseq)15;
    }
}
