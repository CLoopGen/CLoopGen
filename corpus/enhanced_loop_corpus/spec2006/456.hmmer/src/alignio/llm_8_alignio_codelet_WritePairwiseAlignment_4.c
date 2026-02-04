#include <stdio.h>

#include <inttypes.h>

extern int **pam;
extern char buf1[61];
extern char bufmid[61];
extern char buf2[61];
extern int count1;
extern int count2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = (count1 < count2) ? count1 : count2;
for (apos = 0; apos < limit; apos += 2) {
    for (int unroll = 0; unroll < 2; unroll++) {
        int idx = apos + unroll;
        if (idx >= limit) break;
        char c1 = buf1[idx], c2 = buf2[idx];
        int is_special_c1 = (c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
        int is_special_c2 = (c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');
        if (!is_special_c1 && !is_special_c2) {
            if (c1 == c2)
                bufmid[idx] = c1;
            else if (pam[c1 - 'A'][c2 - 'A'] > 0)
                bufmid[idx] = '+';
            else
                bufmid[idx] = ' ';
        } else {
            bufmid[idx] = ' ';
        }
    }
}
}
