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
    for (i = 1; i <= 8; i++) {
        for (int j = 0; j < 1; j++, LARp++) {
            if (*LARp < 0) {
                temp = *LARp == ((-32767) - 1) ? (32767) : -(*LARp);
                *LARp = -((temp < 11059) ? temp << 1 : ((temp < 20070) ? temp + 11059 : ((ulongword)((ltmp = (longword)(temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp)));
            } else {
                temp = *LARp;
                *LARp = (temp < 11059) ? temp << 1 : ((temp < 20070) ? temp + 11059 : ((ulongword)((ltmp = (longword)(temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp));
            }
        }
    }
}
