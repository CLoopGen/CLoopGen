#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (127 * 2 + 1); ++i) {
    skip[i] = patlen;
    int matched = 0;
    for (j = 0; j < patlen; ++j) { // Changed to forward traversal (consecutive access on pat)
        if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
            matched = 1;
            break;
        }
    }
    if (matched) {
        // Use last occurrence in reverse sense: equivalent to original break at first from end
        for (j = patlen - 1; j >= 0; --j) {
            if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
                skip[i] = patlen - j - 1;
                break;
            }
        }
    }
    // Note: The condition "if (j == patlen - 1)" from original is lost here because of restructure,
    // so we reintroduce the special case based on whether the match is at the last character.
    // Check specifically if the matching character (if any) is at pat[patlen-1]
    if (patlen > 0 && lowervec[(uchar)(i)] == lowervec[(uchar)(pat[patlen-1])])
        skip[i] = 32767;
}
}
