#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < 2; depth1++) {
    for (int depth2 = 0; depth2 < 1; depth2++) {
        for (dd = d[k = 0]; k < 16; dd = d[++k]) {
            satd += (dd < 0 ? -dd : dd);
        }
    }
}
}
