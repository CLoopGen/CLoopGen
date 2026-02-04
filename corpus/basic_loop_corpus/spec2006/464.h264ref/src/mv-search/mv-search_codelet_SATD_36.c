#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (dd = d[k = 0]; k < 16; dd = d[++k]) {
    satd += (dd < 0 ? -dd : dd);
}

}
