#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with size 144 (12x12), as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop to continue until boundary
    }

    // Ensure that bking_loc is set such that l starts at bking_loc + 11 and remains within bounds
    // We want the loop to run multiple times but not overflow the array
    // Let’s set bking_loc so that we start near the beginning but can increment by 11 several times
    bking_loc = 0;  // Then l starts at 11

    // Modify part of the board to terminate the loop eventually
    // Find how many times we can add 11 starting from 11 before exceeding 143
    int idx = bking_loc + 11;
    int count = 0;
    int max_steps = 1000000;  // Aim for about 1M iterations to meet ~0.01 sec runtime
    // But our array is only 144, so we cannot have more than (143 - 11) / 11 ≈ 12 steps
    // To make loop run longer, we need to reinterpret or scale up data?

    // However, note: board size is fixed at 144. The loop runs while board[l] == 13
    // So maximum legal l index is 143. Starting from bking_loc+11, stepping by 11.
    // Max number of steps: floor((143 - (bking_loc+11)) / 11) + 1
    // With bking_loc=0, l starts at 11, then 22, ..., 132, 143 -> 143-11=132, 132/11=12 → 13 steps

    // This is too short for 0.01s? Actually 13 steps is negligible.

    // But the problem says: "suggest 1MB–256MB of input data" — however, board is fixed at 144 ints = 576 bytes.
    // Contradiction: either we must respect the array size or scale it.

    // Re-read: "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"
    // But the loop condition depends on board[l] == 13, and l increases by 11 each time.
    // With fixed-size board, we cannot run long unless we wrap or have very large board.

    // However, the extern declaration is `int board[144];` — so we must keep that size.

    // Therefore, we cannot change the array size. The loop will run only a few iterations.

    // But requirement: avoid out-of-bounds access. So we must ensure l stays within [0,143].

    // Strategy:
    // Set bking_loc such that initial l = bking_loc + 11 is within bounds.
    // And set a sentinel value where the loop stops before going out of bounds.

    // Let’s allow the loop to run exactly 10 times and then stop by setting a non-13 value.
    // We'll set bking_loc = 0 → l starts at 11.
    // Then sequence: 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143 → next would be 154 (invalid)
    // So valid indices: up to 143.

    // We need to break before accessing beyond 143.
    // So set board[143] to something other than 13 so that when l reaches 143, the loop stops after that iteration?
    // But condition is checked before body — actually no body, just check.

    // Loop: for (l = bking_loc + 11; board[l] == 13; l += 11) ;

    // So when l becomes 143, it checks board[143]. If it's 13, then loop continues, then l += 11 → l=154, then next check would be board[154] → out of bounds.

    // Therefore, we must ensure that when l would become >=144 in the next iteration, the current iteration does not proceed.

    // So set one element to break the chain before l goes out of bounds.

    // Let’s break at l = 132: after processing l=132, l += 11 → 143, then check board[143]. If board[143] != 13, loop stops.

    // So set board[143] = 0.

    board[143] = 0;

    // Now the loop:
    // l starts at 11 → board[11]==13 → continue
    // ... up to l=132: board[132]==13 → continue → l becomes 143
    // check board[143] == 0 → false → exit loop.

    // So total iterations: (132 - 11) / 11 + 1 = 12 / 11 + 1 → wait: 11,22,...,132 → (132-11)/11 + 1 = 121/11+1=11+1=12 iterations.

    // That's acceptable. No out-of-bounds.

    // But 12 iterations is far below 0.01s — but we cannot help due to fixed array size.

    // The requirement says: "unless the length is specified when the array is declared" — here it is: [144]
    // So we follow the declared size.

    // Thus, we initialize as above.

    // Already set bking_loc = 0 above implicitly? Let's set explicitly.
    bking_loc = 0;

    // Also, we already modified board[143] = 0.
    // All other elements are 13 from earlier initialization.
}