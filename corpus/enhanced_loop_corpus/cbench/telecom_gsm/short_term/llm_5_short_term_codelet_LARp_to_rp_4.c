#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *LARp;
extern int i;
extern word temp;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= 8; i++ , LARp++) {
    if (*LARp == 0) {
        *LARp = 0;
        continue;
    }

    temp = (*LARp < 0) 
        ? ((*LARp == ((-32767)-1)) ? 32767 : -(*LARp))
        : *LARp;

    ltmp = (longword)(temp >> 2) + (longword)(26112);

    if (temp < 11059) {
        *LARp = (temp < 0 ? - (temp << 1) : temp << 1);
    } else if (temp < 20070) {
        *LARp = (temp < 0 ? - (temp + 11059) : temp + 11059);
    } else {
        longword result = ((ulongword)(ltmp - ((-32767)-1)) > (32767) - ((-32767)-1))
            ? (ltmp > 0 ? 32767 : ((-32767)-1))
            : ltmp;

        *LARp = (*LARp < 0) ? -result : result;
    }
}
}
