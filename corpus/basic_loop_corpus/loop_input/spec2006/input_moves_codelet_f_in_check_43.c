#include <stdio.h>
#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with size 144 (12x12), as declared
    for (int i = 0; i < 144; i++) {
        board[i] = 13; // Set default value so loop condition holds initially
    }

    // Ensure that bking_loc is set such that l starts at bking_loc + 11
    // and we avoid out-of-bounds access when incrementing by 11
    // We want the loop to run for many iterations to achieve ~0.01s runtime
    // But board is only 144 elements, so we cannot use large data beyond that

    // To meet performance target, we must consider: modern CPU does billions of ops/sec
    // However, this loop is very simple: one comparison and one addition per iteration
    // On a 3GHz CPU, 0.01s ≈ 30 million cycles — but the loop might run one iteration per cycle
    // So aim for ~10-30 million iterations

    // But our board is only 144 in size — we cannot support millions of iterations safely
    // Therefore, we must reinterpret: perhaps "data size" refers to input footprint?
    // Since board is fixed at 144, we cannot scale it.

    // Instead, we ensure no out-of-bounds access and make the loop run within bounds.
    // Maximum safe sequence: starting from index `start`, stepping by 11 until >= 144
    // We need: l = bking_loc + 11 + 11*k < 144 → max k is floor((143 - (bking_loc+11)) / 11)

    // To maximize iterations within 144, set bking_loc as small as possible such that l starts early
    // Let’s set bking_loc = 0 → l starts at 11
    // Then indices: 11, 22, 33, ..., up to ≤ 143 → last is 132 (11*12) → 12 iterations
    // This is too few.

    // But note: the problem says “suggest 1MB–256MB” — implies we should have large data
    // However, the array is declared as `int board[144]` → 144 * 4 = 576 bytes

    // Contradiction: either the array size is fixed or we can change it?

    // The instruction says: "Define all extern variables referenced in the loop"
    // And the loop uses `board[144]` — so it's fixed size.

    // Therefore, we cannot satisfy 0.01s runtime with meaningful computation unless we misinterpret.

    // Alternative interpretation: maybe the provided loop code is just an example,
    // and we are allowed to scale the data? But the declaration is explicit.

    // Re-read: “Uses a data size that ensures the original loop runs in approximately 0.01 seconds”
    // But if the data is fixed at 144 ints, we cannot scale.

    // Conclusion: the array size is fixed. We must initialize within bounds.
    // The loop will naturally be very fast (< 1 microsecond). We cannot help that.

    // Proceed with safe initialization within array bounds.

    bking_loc = 0; // so l starts at 11

    // Now set a point where the loop stops — currently all are 13, so it would go until out of bounds
    // We must break before l >= 144

    // Find the largest index reachable: start at 11, step by 11: 11,22,...,132,143
    // 11 + 11*k < 144 → k < 12.09 → k=0..12 → indices: 11 to 143 (if 143 is valid)
    // 11*13 = 143 → index 143 is valid (0..143)

    // So next would be 143+11=154 → invalid

    // But at l=143: we check board[143], then do l += 11 → l=154, then exit
    // So accessing board[143] is okay, but not beyond

    // However, if board[l] == 13 at l=143, we do l += 11 → l=154, then check condition again?
    // No: the loop is: for(init; condition; increment) { }
    // Step:
    //   l = bking_loc+11  → l=11
    //   while (board[l] == 13): body is empty, then l += 11
    //   so after increment, it checks condition again

    // So when l=143: check board[143]==13 → true → enter loop → increment to 154
    // Then next iteration: check board[154] → out of bounds!

    // Therefore, we must break the chain before l reaches a value such that l+11 >= 144
    // We need to set one element to non-13 before the last step.

    // Let’s break at l=132: so that when l=132, we do l+=11 → l=143, then check board[143]
    // But then if board[143]==13, we’d enter and increment to 154 → bad

    // Actually, the condition is checked *before* entering the loop body.
    // The structure:
    //   l = bking_loc+11;
    //   while (board[l] == 13) {
    //       l += 11;
    //   }

    // So when l=143: we check board[143] — if 13, then we do l += 11 → l=154
    // Then the next check would be board[154] — which is invalid

    // But wait: after increment, control goes back to condition check — which accesses board[l] with l=154
    // That is undefined behavior.

    // Therefore, we must ensure that the loop terminates before l reaches any index from which adding 11 would exceed 143.

    // Specifically, we require that when l is such that l+11 >= 144, then board[l] != 13
    // So for l >= 133, we must have board[l] != 13

    // In our case, the sequence is: 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143
    // 132+11=143 -> valid
    // 143+11=154 -> invalid
    // So at l=143, if board[143]==13, we do l=154, then check board[154] → crash

    // Thus, we must set board[143] to something other than 13

    // But note: the loop condition is checked at l=143 — so we must not access board[143] if 143>=144? No, 143<144
    // So we do access board[143]. But after incrementing from 143, we get 154, and then the condition is checked again — which requires board[154]

    // Therefore, to prevent out-of-bounds access, we must break the loop before l becomes 143

    // How? By ensuring that at some l < 143 in the sequence, board[l] != 13

    // The last safe index to allow continuation is 132: because 132+11=143 < 144 → valid access
    // Then at l=143, we check board[143] — if it's not 13, we break without incrementing beyond

    // But after breaking at 143, we don't increment — so l remains 143

    // However, the increment happens *inside* the loop body, which runs only if the condition passes

    // Sequence:
    //   l = 132 → board[132]==13 → enter loop → l becomes 143
    //   then back to condition: check board[143]
    //   if board[143]!=13 → exit, l=143

    // So accessing board[143] is okay, as long as 143 < 144 → yes.

    // But what about after that? The loop exits.

    // So the only problematic case is if we ever set l to a value >=144 and then access board[l]

    // Therefore, we can let the sequence go up to 143, but we must not have board[143]==13

    // Because if board[143]==13, then:
    //   l=143 → condition true → execute l += 11 → l=154
    //   then go back to condition: check board[154] → out of bounds

    // So we must set board[143] != 13

    // Similarly, we could break earlier.

    // Plan:
    //   Set all board[i] = 13 for i in the diagonal sequence: 11,22,...,132
    //   Set board[143] = 0 (or any not 13)

    // But note: bking_loc + 11 must be 11 → so bking_loc=0

    // Also, we must ensure that no other out-of-bound access occurs.

    // Let's reinitialize:

    for (int i = 11; i <= 132; i += 11) {
        board[i] = 13;
    }
    board[143] = 0; // break the loop

    // Other positions can be arbitrary, say 0
    for (int i = 0; i < 144; i++) {
        if (i % 11 == 0 && i >= 11 && i <= 132) continue;
        if (i == 143) continue;
        board[i] = 0;
    }

    bking_loc = 0; // so l starts at 11

    // l is modified by the loop, so its initial value doesn't matter much
    // but set to 0 for determinism
    l = 0;
}