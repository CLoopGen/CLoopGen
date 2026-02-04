#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashseq;

extern char *sequence;
extern long i;
extern Hashseq target;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < (sizeof(Hashseq) * 2); i++) {
    if (*(sequence + i) == 0)
        break;
    target <<= 4;
    target |= (Hashseq)(*(sequence + i));
}

}
