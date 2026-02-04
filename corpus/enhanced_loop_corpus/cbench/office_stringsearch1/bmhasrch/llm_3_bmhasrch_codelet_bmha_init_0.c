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
// Strided memory access on 'skip' array with unroll-like simulation (stride of 2)
// Process two indices per iteration to change access pattern
int upper_bound = (127 * 2 + 1);
for (i = 0; i <= upper_bound; i += 2) {
    // Handle i and i+1 separately but within same iteration
    for (int offset = 0; offset < 2; ++offset) {
        int idx = i + offset;
        if (idx > upper_bound) continue;

        skip[idx] = patlen;
        int found_match = 0;
        // Traverse pattern backwards, but use indirect access via index remapping
        for (j = patlen - 1; j >= 0; --j) {
            int pat_index = (j * 7) % 256; // Indirect access into pat using modular hashing (artificial indirection)
            uchar pat_char = pat[pat_index];
            if (lowervec[(uchar)(idx)] == lowervec[pat_char]) {
                found_match = 1;
                j = pat_index; // Store effective position as transformed index
                break;
            }
        }
        if (found_match) {
            skip[idx] = patlen - j - 1;
            // Re-check if original last character matches (preserve logic despite indirection)
            if (lowervec[(uchar)(idx)] == lowervec[(uchar)(pat[patlen-1])])
                skip[idx] = 32767;
        }
    }
}
}
