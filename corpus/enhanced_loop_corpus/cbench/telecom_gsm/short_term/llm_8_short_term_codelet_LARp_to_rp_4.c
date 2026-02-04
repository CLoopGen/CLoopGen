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
    for (i = 0; i < 16; i += 2, LARp++) {
        if (*LARp < 0) {
            temp = *LARp == ((-32767) - 1) ? (32767) : -(*LARp);
            if (temp < 11059) {
                *LARp = temp << 1;
            } else if (temp < 20070) {
                *LARp = temp + 11059;
            } else {
                ltmp = (longword)(temp >> 2) + (longword)(26112);
                if (ltmp > 32767) {
                    *LARp = 32767;
                } else if (ltmp < (-32767)-1) {
                    *LARp = (-32767)-1;
                } else {
                    *LARp = (word)ltmp;
                }
            }
        } else {
            temp = *LARp;
            if (temp < 11059) {
                *LARp = temp << 1;
            } else if (temp < 20070) {
                *LARp = temp + 11059;
            } else {
                ltmp = (longword)(temp >> 2) + (longword)(26112);
                if (ltmp > 32767) {
                    *LARp = 32767;
                } else if (ltmp < (-32767)-1) {
                    *LARp = (-32767)-1;
                } else {
                    *LARp = (word)ltmp;
                }
            }
        }
        LARp++; 
        i++; 
    }
}
