#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long indices[] = {0, 2, 4, 6, 1, 3, 5, 7}; // Example strided and reordered access
    long num_elements = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_elements; i++) {
        long idx = indices[i];
        if (idx >= (sizeof(Hashseq) * 2))
            continue;
        char c = *(sequence + idx);
        if (c == 0)
            break;
        target <<= 4;
        target |= (Hashseq)c;
    }
}
