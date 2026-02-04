#include <stdio.h>

#include <inttypes.h>

extern int holding[2][16];
extern int num_holding[2];
extern unsigned int zobrist[14][144];
extern unsigned int hold_hash;
extern char str[];
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the outer loop for c = 0 and c = 1 explicitly to increase computational intensity
    for (int unroll_c = 0; unroll_c < 2; unroll_c++) {
        c = unroll_c;

        // Find first '[' using a counted loop with bounded search to avoid infinite loops
        int max_search = 256;
        for (i = i; max_search > 0 && str[i] != '['; i++, max_search--);
        if (max_search == 0 || str[i] == 0) return;
        i++; // Advance past '['

        // Use a fixed-size loop to process up to 16 held pieces per side (bounded by num_holding limit)
        int processed = 0;
        for (; processed < 16 && str[i] != ']' && str[i] != 0; processed++) {
            char token = str[i++];
            int offset;

            // Direct lookup using arithmetic instead of switch-case
            if (token >= 'a' && token <= 'z') token &= ~0x20; // Fast uppercase conversion

            if (token == 'P') offset = (c == 0 ? 1 : 2);
            else if (token == 'Q') offset = (c == 0 ? 9 : 10);
            else if (token == 'R') offset = (c == 0 ? 7 : 8);
            else if (token == 'B') offset = (c == 0 ? 11 : 12);
            else if (token == 'N') offset = (c == 0 ? 3 : 4);
            else { i--; break; } // Invalid token, leave for next iteration

            holding[c][offset]++;
            num_holding[c]++;
            hold_hash ^= zobrist[offset][holding[c][offset]];
        }

        // If we hit null terminator during processing, exit early
        if (str[i] == 0) return;
    }
}
