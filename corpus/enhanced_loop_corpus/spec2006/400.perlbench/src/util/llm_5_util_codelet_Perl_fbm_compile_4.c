#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef unsigned int U32;

typedef size_t STRLEN;

typedef int I32;

extern const unsigned char PL_freq[];
extern U8 *s;
extern U32 i;
extern STRLEN len;
extern I32 rarest;
extern U32 frequency;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        U32 freq_val = PL_freq[s[i]];
        if (freq_val < frequency) {
            rarest = i;
            frequency = freq_val;
        } else {
            if (freq_val == frequency && rarest == -1) {
                rarest = i;
            }
        }
    }
}
