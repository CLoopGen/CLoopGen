#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (sizeof(Hashseq) * 2); i++) {
        if (*(sequence + i) == 0) {
            break;
        }
        if (*(sequence + i) >= 'A' && *(sequence + i) <= 'F') {
            target <<= 4;
            target |= (Hashseq)(*(sequence + i) - 'A' + 10);
        } else if (*(sequence + i) >= '0' && *(sequence + i) <= '9') {
            target <<= 4;
            target |= (Hashseq)(*(sequence + i) - '0');
        }
    }
}
