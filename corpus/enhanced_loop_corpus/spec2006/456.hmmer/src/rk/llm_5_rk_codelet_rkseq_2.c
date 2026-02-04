#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (sizeof(Hashseq) * 2); i++) {
        char c = *(sequence + i);
        if (c == 0) break;
        if (c < '0' || (c > '9' && c < 'A') || c > 'F') continue;
        target <<= 4;
        if (c >= 'A') {
            target |= (Hashseq)(c - 'A' + 10);
        } else {
            target |= (Hashseq)(c - '0');
        }
    }
}
