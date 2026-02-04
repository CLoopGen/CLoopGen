#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int j;
extern int a;
extern int i;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access Pattern
    // Use an auxiliary index array to indirectly access the pieces array.
    // This simulates a gather-style access pattern where indices are not sequential.
    // We create a small local indirect index mapping to simulate realistic indirect access.
    int indices[32];
    for (int idx = 0; idx < 32; idx++) {
        indices[idx] = (idx * 7) % 61 + 1;  // Generate non-sequential but valid indices into pieces[1..61]
    }
    a = 1;
    for (j = 0; (a <= piece_count) && (j < 32); j++) {
        i = pieces[indices[j]];  // Indirect access via precomputed indices
        if (!i)
            continue;
        else
            a++;
        switch (board[i]) {
          case 1:
          case 11:
          case 7:
          case 5:
          case 9:
          case 3:
            wp++;
            break;
          case 2:
          case 12:
          case 8:
          case 6:
          case 10:
          case 4:
            bp++;
            break;
        }
        if (wp && bp)
            break;
    }
}
