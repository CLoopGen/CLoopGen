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
    // Eliminate loop-carried dependencies by precomputing bounds and using forward progress
    int local_hold_hash = hold_hash; // Break WAW dependency on shared hold_hash
    int temp_holding[2][14] = {0};   // Local copy to break WAR/WAW on holding[]
    int temp_num_holding[2] = {0};   // Local accumulator to reduce data races

    // Initialize temp arrays with current holding state
    for (int c_init = 0; c_init < 2; c_init++) {
        for (int p = 1; p < 14; p++) {
            temp_holding[c_init][p] = holding[c_init][p];
        }
        temp_num_holding[c_init] = num_holding[c_init];
    }

    for (c = 0; c <= 1; c++) {
        // Find start of section [
        for (; str[i] != 0 && str[i] != '['; i++);
        if (str[i] == 0) {
            hold_hash = local_hold_hash;
            return;
        }
        i++; // Skip '['

        // Process tokens without indirect memory updates
        for (; str[i] != ']' && str[i] != 0; i++) {
            int offset;
            switch (str[i]) {
                case 'p': case 'P':
                    offset = c == 0 ? 1 : 2;
                    break;
                case 'q': case 'Q':
                    offset = c == 0 ? 9 : 10;
                    break;
                case 'r': case 'R':
                    offset = c == 0 ? 7 : 8;
                    break;
                case 'b': case 'B':
                    offset = c == 0 ? 11 : 12;
                    break;
                case 'n': case 'N':
                    offset = c == 0 ? 3 : 4;
                    break;
                default:
                    hold_hash = local_hold_hash; // Restore global only on error
                    return;
            }

            // Update local state only
            temp_holding[c][offset]++;
            temp_num_holding[c]++;
            local_hold_hash ^= zobrist[offset][temp_holding[c][offset]];
        }
    }

    // Commit all changes atomically at the end to eliminate intra-loop dependencies
    for (int c_commit = 0; c_commit < 2; c_commit++) {
        num_holding[c_commit] = temp_num_holding[c_commit];
        for (int p = 1; p < 14; p++) {
            holding[c_commit][p] = temp_holding[c_commit][p];
        }
    }
    hold_hash = local_hold_hash;
}
