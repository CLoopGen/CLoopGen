#include <stdio.h>
#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize board array
    for (int i = 0; i < 144; i++) {
        board[i] = 13;  // Set all elements to 13 to allow loop to progress
    }

    // Ensure that the loop will terminate by setting a sentinel value beyond a safe bound
    // The loop starts at wking_loc + 12 and increments by 12 each time
    // Choose wking_loc so that we have enough space to traverse without overflow

    wking_loc = 0;  // Start from index 0 for base

    // We need to break the loop eventually — set a value != 13 at a controlled position
    // Loop checks board[l] == 13, so set board[some_l] to something else
    // Let's allow the loop to run through about 10 million steps for ~0.01 sec runtime

    const long target_steps = 10000000;  // ~10M iterations expected in 0.01s
    const long final_index = wking_loc + 12 * target_steps;

    // But our board is only size 144 -> indices 0 to 143
    // So we cannot safely go beyond 143. Therefore, we must limit traversal within bounds

    // Instead, adjust logic: since board size is fixed at 144, we cannot support large strides.
    // So we make the loop terminate quickly but are ready if board were larger.

    // However, requirement says: "data size that ensures the original loop runs in approximately 0.01 seconds"
    // So we must scale up data — but board is declared as [144]. We cannot change its size without breaking ABI.

    // Conflict: array size is fixed at 144, which is very small (~576 bytes). 
    // A loop over it would finish in microseconds.

    // To meet timing requirement, we interpret that we may *adjust* the problem to use scalable data,
    // but the function references `board[144]` externally — so we cannot change size.

    // Alternative: perhaps the given `board[144]` is just an example? But the code uses exact indexing.

    // Since we must satisfy both constraints:
    // - Keep board[144] as declared
    // - Make loop take ~0.01s
    // We realize this is impossible unless each iteration is artificially slowed.

    // But no such mechanism is allowed. So instead, re-read: "suggest 1MB–256MB" — only a suggestion if length not specified.
    // Here, length *is* specified: 144.

    // Therefore, we follow correctness first: keep board size 144, initialize safely.

    // Find maximum possible l: start at wking_loc+12, then +12 repeatedly
    // Max index before out of bounds: 143
    // So we require l <= 143

    // Set wking_loc to 1 -> l starts at 13
    // Then sequence: 13, 25, 37, ..., up to ≤143
    // This arithmetic sequence: 13 + 12*k ≤ 143 → k ≤ (130)/12 ≈ 10.8 → k=10 → last=133
    // Next would be 145 → invalid.

    // So we can let it run safely up to index 133, then set board[145] isn't accessible.

    // But we cannot access board[145]. So we must break before l >= 144.

    // Strategy:
    // Set wking_loc = 1 → l starts at 13
    // Set all board[i] = 13 for i in [13, 133] (i.e., indices accessible)
    // Then ensure board[145] is not accessed — but we can't write to it anyway.

    // Instead, break the loop earlier: set one element in the sequence to non-13
    // But we want predictable, safe execution.

    // Actually, the loop condition is checked at each step including initial.
    // So if we set wking_loc = 1, then l = 13, check board[13]==13?
    // If yes, continue until fails.

    // We can allow it to run through valid indices and stop when l reaches 145? No — accessing board[145] is UB.

    // Therefore, we must ensure that before l reaches >=144, the loop stops.

    // How? Either:
    // 1. Set one board[l] != 13 within bounds
    // 2. Or ensure l never goes out of bounds by having the condition fail early

    // We choose option 1.

    // Let’s set the last accessible index in the sequence to break the chain.

    // Valid indices in sequence starting from wking_loc+12 with step 12:
    // Let base = wking_loc + 12
    // We pick wking_loc = 0 → base = 12
    // Sequence: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144 → 144 is out of bounds (max index 143)

    // So last valid is 132. Then next is 144 → invalid.

    // So we can safely set board[12], [24], ..., [132] to 13
    // And we don’t care about board[144] because we shouldn't read it.

    // But the loop reads board[l] at l=144 if it gets there.

    // So we must break the loop before l becomes 144.

    // Therefore, we set one of the middle elements to non-13 so loop terminates early.

    // But we also need to consider performance: we want ~0.01s runtime, but 12 iterations is too fast.

    // Given the contradiction between fixed small array and desired runtime, we conclude:
    // The extern array declaration might be incomplete or placeholder.

    // However, the problem states: "Define all extern variables ... with correct types" — and type is `int board[144]`.

    // So we stick to board[144].

    // Accept that loop will execute in nanoseconds, but at least be safe.

    // Final safe initialization:

    wking_loc = 0;
    for (int i = 12; i <= 132; i += 12) {
        board[i] = 13;
    }
    // Set one past the last valid multiple to break the loop naturally via condition fail?
    // But we can't control what's beyond.

    // Instead, break early: set last in-bounds to non-13
    board[132] = 0;  // so when l=132, board[l]!=13 → loop stops

    // But then loop body doesn't run?

    // We want the loop to run several times but stay safe.

    // Let’s allow it to run 10 times: indices 12,24,...,120
    // Then at l=132, we break either by condition or by design

    // But 10 iterations is still too few for 0.01s? Not measurable.

    // Given the constraints, we prioritize safety and correctness over timing.

    // Reinitialize: set all multiples of 12 from 12 to 120 to 13, and 132 to 0
    for (int i = 12; i <= 120; i += 12) {
        board[i] = 13;
    }
    board[132] = 0;  // break condition

    // Also initialize other values in board to avoid garbage, though not used
    for (int i = 0; i < 144; i++) {
        if (i % 12 != 0 || i < 12 || i > 120) {
            if (!((i>=12 && i<=120) && i%12==0))
                board[i] = 0;
        }
    }

    // However, note: the loop starts at wking_loc+12, so if wking_loc=0, start=12 → good.
    l = 0; // initial value irrelevant, overwritten in loop
}