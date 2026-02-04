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
    for (i = 1; i <= 4; i++, LARp++) {
        temp = *LARp < 0 ? (*LARp == ((-32767)-1) ? 32767 : -(*LARp)) : *LARp;

        if (temp >= 20070) {
            ltmp = (longword)(temp >> 2) + 26112;
            *LARp = (ltmp > 32767) ? 32767 : (ltmp < (-32767)-1 ? (-32767)-1 : (word)ltmp);
        } else if (temp >= 11059) {
            *LARp = temp + 11059;
        } else {
            *LARp = temp << 1;
        }

        if (*LARp < 0 && (*LARp & 1)) {
            *LARp = (*LARp << 1) + 1;
        }
    }
}
