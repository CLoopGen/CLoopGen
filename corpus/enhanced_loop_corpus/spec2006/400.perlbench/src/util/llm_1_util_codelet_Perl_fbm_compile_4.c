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
    if (len > 0) {
        i = 0;
        for (; i < len; i++) {
            if (PL_freq[s[i]] < frequency) {
                rarest = i;
                frequency = PL_freq[s[i]];
            }
            {
                // Artificial nested block with no-op inner loop to increase nesting depth
                for (U32 dummy = 0; dummy < 1; dummy++) {
                    continue;
                }
            }
        }
    }
}
