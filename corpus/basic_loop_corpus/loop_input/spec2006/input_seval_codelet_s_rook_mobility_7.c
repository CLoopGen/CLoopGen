#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize the board array: set most elements to 13 to allow loop continuation
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Ensure that we do not go out of bounds in the loop: l += 12 starting from square+12
    // We want to stop before exceeding board[143]. Let square + 12*k < 144 => k < (144 - square)/12
    // Choose square such that there are many iterations but no overflow.
    // Max l should be <= 143. Let square = 0, then l starts at 12 and increments by 12.
    // Valid indices: 12, 24, ..., 132, 144 -> but 144 is out of bounds (max index 143)
    // So we must prevent l from reaching 144. Set board[144] would be invalid.

    // Adjust: only indices 0..143 are valid. Largest multiple of 12 less than 144 is 132.
    // So if we start at square+12 and step by 12, last valid is 132 -> next would be 144 (invalid).
    // To avoid out-of-bounds access, ensure that when l reaches 132, the next increment would break condition because l >= 144?
    // But the loop checks board[l] after incrementing l — so l must always be < 144.

    // Therefore, we must break before l becomes >= 144.
    // Strategy: set square = 0 so l starts at 12.
    // Then valid l values: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 -> next 144 invalid.
    // So we can have 11 iterations maximum? But we want more iterations to meet time requirement (~0.01s).

    // However, the array size is fixed at 144. This limits us to at most 11 steps (since 12 * 12 = 144).
    // But 11 iterations is too few to take 0.01s — each iteration is a few cycles.

    // Observation: the problem says "suggest 1MB–256MB" but the array is declared as [144] — this is fixed.
    // So we cannot change the array size. The loop logic is constrained by this.

    // But note: the loop runs while board[l] == 13. If we could make it run many times, but within bounds.
    // With fixed board size 144, stepping by 12, we can only hit 11 elements (from index 12 to 132 inclusive).
    // So maximum m increments is 11.

    // This will run in nanoseconds. We cannot achieve 0.01 seconds without changing data size.

    // Re-read: "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"
    // But the array is declared as `extern int board[144];` — so we must define it with size 144.

    // Compromise: we follow the declaration strictly. The performance target may not be met due to fixed small size,
    // but we ensure correctness and maximal possible iterations.

    square = 0;  // l starts at 12
    m = 0;

    // Terminate the sequence before out-of-bounds: set an element beyond the intended chain to break the loop.
    // We let the loop run for all valid multiples of 12 starting from 12 up to 132 (inclusive).
    // That’s indices: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 → 11 elements.
    // After l=132, next l=144 which is out of bounds. But the loop condition checks board[l] at l=144 → undefined behavior.

    // Prevent UB: we must ensure the loop stops before l >= 144.
    // Idea: don’t rely on bound check — instead, break the chain by setting one value not equal to 13.
    // But the loop starts at l = square+12 = 12, then checks board[12], then l+=12 → l=24, etc.
    // We can safely set board[144] doesn't exist.

    // Instead, we break the loop early by setting one element to non-13.
    // But we want as many iterations as possible without UB.

    // Actually, the loop condition is checked at each l value. When l becomes 144, we access board[144] → out of bounds.
    // So we must ensure that the loop never tries to access board[144].

    // How? Only if at some point before l reaches 144, board[l] != 13.
    // So we set board[132] to something other than 13? Then m only increments 10 times.

    // Alternatively, we can adjust square so that even after several steps, l stays below 144.
    // But maximum starting point: if square = 131, then l = 143 → board[143]==13? then l +=12 → 155 → invalid.
    // No help.

    // Conclusion: the loop as written has potential for out-of-bounds access.
    // We must initialize so that the loop terminates before l >= 144.

    // Safe approach: set the last accessible element in the sequence to break the loop.
    // Sequence: l = square+12, then l +=12 repeatedly.
    // Let square = 0 → l starts at 12.
    // Elements accessed: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 → next would be 144 (invalid).
    // So we allow the first 10 steps to continue, but break at l=132 by setting board[132] != 13.
    // Then m will be incremented 10 times.

    // But wait: the loop body runs when board[l] == 13. It checks board[l], if true, enters loop and does m++.
    // So if board[132] == 13, it will execute m++, then l +=12 → l=144, then next iteration checks board[144] → UB.

    // Therefore, to prevent UB, we must ensure that when l=132, board[132] != 13, so the loop exits after m++ for l=120.

    // Steps:
    // l = 12 → board[12]=13 → m=1 → l=24
    // ...
    // l = 120 → board[120]=13 → m=10 → l=132
    // Then check board[132]: if 13 → m=11 → l=144
    // Then check board[144] → invalid.

    // So to prevent accessing board[144], we need the loop condition to fail at l=132.
    // Therefore, set board[132] = 0 (or any value !=13).

    // Now the loop will run for l=12,24,...,120 (10 times), then at l=132, condition fails.

    // But what if square is larger?

    // We control square. Let's set square = 0, and fix the board accordingly.

    // Reset: keep all board[i] = 13 except where necessary to prevent UB.
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    // Break the chain at l=132: set board[132] to non-13
    board[132] = 0;

    square = 0; // so l starts at 12
    m = 0;
}