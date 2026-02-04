#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *perm;
extern UChar *length;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 alphaSize;
extern Int32 pp;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via index remapping
    // We create a precomputed indirect access order (simulated via alternating low/high ends)
    // to increase memory access irregularity, which might model scenarios with non-sequential
    // symbol processing. Since we cannot introduce new arrays, we simulate indirect indexing
    // using arithmetic that alternates between beginning and end of the alphabet.

    Int32 *temp_perm = perm; // Local alias for clarity
    UChar *temp_length = length;
    Int32 idx;

    for (i = minLen; i <= maxLen; i++) {
        // Traverse indices in an indirect order: from both ends toward center
        for (j = 0; j < (alphaSize + 1) / 2; j++) {
            // Left-to-right index
            idx = j;
            if (temp_length[idx] == i) {
                temp_perm[pp] = idx;
                pp++;
            }

            // Right-to-left index (avoid double counting center in odd case)
            idx = alphaSize - 1 - j;
            if (idx != j && idx >= 0 && idx < alphaSize) {
                if (temp_length[idx] == i) {
                    temp_perm[pp] = idx;
                    pp++;
                }
            }
        }
    }
}
