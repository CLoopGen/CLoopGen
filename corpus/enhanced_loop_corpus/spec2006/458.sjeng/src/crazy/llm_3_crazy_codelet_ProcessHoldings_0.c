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
    // Precomputed mapping from ASCII to piece type index (offsets for 'b', 'n', 'p', 'q', 'r')
    const int char_to_piece[256] = {
        ['p'] = 1, ['P'] = 1,
        ['q'] = 9, ['Q'] = 9,
        ['r'] = 7, ['R'] = 7,
        ['b'] = 11, ['B'] = 11,
        ['n'] = 3, ['N'] = 3
    };

    for (c = 0; c <= 1; c++) {
        int found_bracket = 0;

        // Find the opening bracket using a counted loop with early exit
        for (i = i; !found_bracket && str[i] != 0; i++) {
            if (str[i] == '[') {
                found_bracket = 1;
            }
        }
        if (!found_bracket) return;
        
        // Traverse until closing bracket using pointer arithmetic simulation via index
        int start = i;
        int pos = start;
        while (str[pos] != ']') {
            pos++;
        }

        // Perform indirect memory access: collect indices first, then update in batch-like fashion
        for (int j = start; j < pos; j++) {
            unsigned char ch = str[j];
            int piece_base = char_to_piece[ch];
            if (piece_base == 0) return; // invalid piece

            int actual_piece = (c == 0) ? piece_base : piece_base + 1;
            int* target_cell = &holding[c][actual_piece];
            
            // Strided access pattern: simulate scatter-gather by precomputing address
            (*target_cell)++;
            num_holding[c]++;
            hold_hash ^= zobrist[actual_piece][(*target_cell)];
        }
        i = pos; // update global index
    }
}
