#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize board: set most elements to 13 to allow loop to iterate
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Choose square such that l starts at a valid index and allows several iterations
    // l = square + 12 must be within [0, 143], and we want to step by 12 until out of bounds
    // To avoid out-of-bounds access, ensure l remains < 144
    // Max l can be: 143 -> so square + 12 <= 143 -> square <= 131
    // We'll pick square = 120 so l starts at 132, then 144 would be next after 132+12=144 -> invalid
    // So only one iteration if board[132]==13, but we want more iterations? Let's adjust.

    // Instead, make sure the loop runs over multiple steps: l = square+12, l+=12 until board[l]!=13
    // We need consecutive multiples of 12 starting from square+12 to be in range.
    // Let’s set square = 0 -> l starts at 12
    // Then l = 12, 24, 36, ..., up to 132 (132+12=144 -> out of bounds)
    // Indices: 12,24,...,132 -> 11 indices. We'll break when l becomes 144.

    // But condition is board[l] == 13, so as long as those are 13, it continues.
    // We already set all to 13. So m will increment for each valid l.

    // However, the loop condition checks board[l] == 13, and increments l by 12 each time.
    // It stops when board[l] != 13 or when l goes beyond array?
    // But no bound check — so we must ensure that we don't access out of bounds.

    // Therefore, we must break before l >= 144.
    // The loop does not have explicit bounds checking, so we must initialize so that eventually board[l] != 13
    // Let’s set board[132] = 13, but board[144] doesn’t exist. So maximum l is 132.
    // So if square+12 > 132, then first access is invalid.

    // Safe: let square = 0 -> l starts at 12, which is valid.
    // Then l goes: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 -> 11 values.
    // Next would be 144 -> out of bounds.

    // So we need to break at 132. But loop has no break — it relies on board[l] != 13 to stop.
    // So we must set one element beyond the desired count to non-13? But we can't access beyond 143.

    // Instead, we rely on the fact that l will become >= 144 and thus cause undefined behavior unless avoided.

    // Therefore, we must ensure the loop terminates due to board[l] != 13 *before* going out of bounds.

    // So set board[132] = 13, but we cannot safely access board[144]. So last valid l is 132.
    // After processing l=132, l += 12 → l=144, then loop checks board[144] → out of bounds.

    // So we must prevent accessing l=144. Therefore, we must make sure that at some point before l>=144,
    // board[l] != 13.

    // Best fix: set board[132] = 0 (not 13), so when l reaches 132, the loop stops without further increment.
    // But wait: l starts at square+12. If square=0, l starts at 12.
    // Sequence: l=12,24,...,120, then next l=132. If board[132]!=13, loop stops.
    // So m counts how many times it saw 13 at positions 12,24,...,120 -> that's 10 positions.

    // So set board[132] = 0 to stop the loop.

    // But what if square is negative? Not safe. So choose square such that square+12 is valid and stepping leads to early termination.

    // Let’s set:
    square = 0;
    m = 0;

    // Re-initialize board: set indices 12,24,...,120 to 13 (10 elements), and 132 to 0
    for (int i = 1; i <= 10; ++i) {
        int idx = i * 12; // 12,24,...,120
        board[idx] = 13;
    }
    board[132] = 0; // This will stop the loop when l=132

    // All other board entries can remain 13 or anything — they won't be accessed
}