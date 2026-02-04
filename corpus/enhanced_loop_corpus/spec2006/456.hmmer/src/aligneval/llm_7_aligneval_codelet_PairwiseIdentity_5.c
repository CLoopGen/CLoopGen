#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int idents;
extern int len1;
extern int len2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_len1 = 0, temp_len2 = 0, temp_idents = 0;
    int i;
    for (i = 0; s1[i] != '\x00' && s2[i] != '\x00'; i++) {
        char c1 = s1[i], c2 = s2[i];
        int match = (c1 == c2);
        int valid1 = !((c1 == ' ') || (c1 == '.') || (c1 == '_') || (c1 == '-') || (c1 == '~'));
        int valid2 = !((c2 == ' ') || (c2 == '.') || (c2 == '_') || (c2 == '-') || (c2 == '~'));
        
        temp_len1 += valid1;
        temp_len2 += valid2;
        temp_idents += (valid1 && match);
    }
    // Eliminate loop-carried dependencies by using local accumulators
    // Final update outside the loop (reduces RAW dependencies in loop body)
    len1 += temp_len1;
    len2 += temp_len2;
    idents += temp_idents;
    x = i - 1; // Update x after loop to remove intra-loop dependency on x
}
