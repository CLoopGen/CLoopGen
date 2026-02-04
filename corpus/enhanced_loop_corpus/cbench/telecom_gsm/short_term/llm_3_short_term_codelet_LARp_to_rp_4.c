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
    // Variant 2: Indirect Memory Access via Index Array (simulated with fixed offset table)
    static const int indices[] = {0, 3, 6, 9, 12, 15, 18, 21}; // Simulate indirect access pattern
    word* base = LARp - 1; // Adjust base so that index 0 corresponds to original start

    for (i = 0; i < 8; i++) {
        word* current = &base[indices[i]];
        if (*current < 0) {
            temp = *current == ((-32767) - 1) ? (32767) : -(*current);
            *current = -((temp < 11059) ? temp << 1 : ((temp < 20070) ? temp + 11059 : ((ulongword)((ltmp = (longword)(temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp)));
        } else {
            temp = *current;
            *current = (temp < 11059) ? temp << 1 : ((temp < 20070) ? temp + 11059 : ((ulongword)((ltmp = (longword)(temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp));
        }
    }
    LARp += 8; // Maintain consistent pointer advance side-effect
}
