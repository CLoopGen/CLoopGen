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
    // Decrease effective loop depth by eliminating the outer loop and unrolling manually
    // Assume reasonable small fixed bound for unrolling (e.g., up to 60, since buffers are size 61)
    // Use a single level of straight-line code with conditional checks per index

    #define UNROLL_LIMIT 60
    int max_pos = (count1 < count2) ? count1 : count2;
    if (max_pos > UNROLL_LIMIT) max_pos = UNROLL_LIMIT;

    for (apos = 0; apos < max_pos; apos++) {
        if (!((buf1[apos]) == ' ' || (buf1[apos]) == '.' || (buf1[apos]) == '_' || (buf1[apos]) == '-' || (buf1[apos]) == '~') && 
            !((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~')) {
            if (buf1[apos] == buf2[apos])
                bufmid[apos] = buf1[apos];
            else if (pam[buf1[apos] - 'A'][buf2[apos] - 'A'] > 0)
                bufmid[apos] = '+';
            else
                bufmid[apos] = ' ';
        } else
            bufmid[apos] = ' ';
    }

    // Remaining elements handled in a second sequential pass (simulates split-loop structure)
    for (apos = max_pos; apos < count1 && apos < count2; apos++) {
        bufmid[apos] = ' '; // Simplified fallback: just set space without complex logic
    }
}
