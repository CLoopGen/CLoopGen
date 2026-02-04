#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a sentinel
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Set a sentinel value to break the loop: find first location beyond bking_loc + 12 in steps of 12
    // Choose bking_loc so that the loop starts at bking_loc + 12 and runs for many iterations but stays in bounds
    // We want approximately 0.01 seconds runtime — this loop is very fast, so we need many iterations.
    // On modern CPUs, each iteration is a few cycles. Assume ~1e9 iterations per second -> 10 million iterations for 0.01s.

    // But our board is only size 144. So we cannot run millions of iterations without going out of bounds.
    // Therefore, adjust problem: we must respect board[144] size.

    // Max possible stride iterations in bounds: starting at bking_loc+12, stepping by 12
    // Need l < 144
    // Let’s say start at index s = bking_loc + 12, then next indices: s, s+12, s+24, ...
    // Maximum s such that s + 12*k < 144 -> k_max = (144 - s) / 12

    // To maximize iterations, set s as small as possible. But bking_loc must be valid index.

    // Instead, since we cannot control data size beyond 144, we must accept that loop will be fast.
    // But requirement says "suggest 1MB–256MB", so we are allowed to change data size?

    // However, the extern declaration says `extern int board[144];` — so we must define it as [144].

    // So we are stuck with small data. But the loop may not run long enough.

    // Re-read: "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"
    // But if the array is fixed at 144, we can't change it.

    // However, note: the header says "extern int board[144];" — but we are defining it.
    // We can choose the definition. But must match the declared size? Only if other code depends on 144.

    // Since the loop uses `l += 12` and checks `board[l]`, and no bounds check, we must ensure l stays < 144.

    // So maximum number of iterations is limited by array size.

    // Example: if bking_loc = 0, then l starts at 12, then 24, 36, ..., up to less than 144.
    // Indices: 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 -> 11 iterations (next would be 144, invalid)

    // That's too few.

    // But wait — the problem says: "generate a self-contained C source file that defines and initializes all those external symbols"

    // And the extern declaration says `int board[144]`, so we must define an array of 144 ints.

    // Therefore, we cannot make it larger.

    // However, perhaps the loop is part of a larger context where bking_loc is chosen so that the loop runs over available elements.

    // We must ensure no out-of-bounds access.

    // Strategy:
    // - Set bking_loc so that l starts at a valid index: l = bking_loc + 12 must be < 144 -> bking_loc < 132.
    // - We want as many iterations as possible within bounds.
    // - The sequence: l = bking_loc + 12, bking_loc + 24, ... until l >= 144 or board[l] != 13.

    // To have many iterations, set bking_loc = 0 -> l starts at 12, then 24, ..., 132 -> 11 iterations.

    // But 11 iterations is acceptable because we cannot do more without violating array bounds.

    // However, the requirement about 0.01 seconds seems unachievable with this array size.

    // But note: the requirement says "unless the length is specified when the array is declared" — here it is specified as 144.

    // So we follow the declared size.

    // Initialize all board elements to 13, except set one element beyond the last valid step to break the loop.

    // Actually, we don't need to break early — we can let it break naturally when l goes out of bounds?
    // But the loop condition checks board[l] — which would be undefined behavior if l>=144.

    // So we must break before l reaches 144.

    // Therefore, we must set a non-13 value at the last possible position in the sequence.

    // Find the longest arithmetic sequence starting from >=12, step 12, within [0,143].

    // Start at 12: 12,24,...,132 -> 11 terms (index 0-based: 132 is valid, next 144 invalid)
    // So we can allow 10 iterations with board[l]==13, then at l=132, set board[132] to something else?

    // But the loop condition is: for (l = bking_loc+12; board[l]==13; l+=12)

    // So at l=132, if board[132]!=13, the loop body (which is empty) doesn't run, and l remains at 132.

    // But the increment happens after the body — so the sequence of l values during condition check:
    // First: l = bking_loc+12 -> check board[l]
    // Then if true, enter body (empty), then l += 12, then check board[l] again.

    // So we need to have board[l] == 13 for all l in the sequence until the last valid one, and then at the next l (which would be beyond) we cannot access.

    // Therefore, we must break the chain before accessing l>=144.

    // So we must set board[l] != 13 at the last l that is <144 and is in the sequence.

    // But then the loop stops there, and does not increment to an invalid index.

    // How to maximize iterations:

    // Let bking_loc = 0 -> l starts at 12.
    // We want board[12]==13, board[24]==13, ..., board[120]==13, board[132] != 13.

    // Then the loop:
    //   l = 12 -> board[12]==13 -> enter loop body (empty) -> l +=12 -> l=24
    //   ... until
    //   l = 132 -> board[132] != 13 -> exit loop
    // But wait: the condition is checked at the beginning of each iteration.

    // The value of l after the loop is the first value for which board[l] != 13.

    // So we must have board[132] != 13 to prevent the loop from trying to go to 144.

    // But what if we set bking_loc such that the starting index is lower?

    // Minimum starting index: bking_loc+12 >=0 -> bking_loc >= -12, but bking_loc should be valid index? Not necessarily.

    // However, board[bking_loc] might be accessed elsewhere? But not in this loop.

    // But we are only told about this loop.

    // So we can set bking_loc = -12 -> then l starts at 0.

    // Then sequence: 0,12,24,...,132 -> 12 terms.

    // Then we must set board[132] != 13 to break.

    // So 11 full iterations (body executed 11 times: at l=0,12,...,120) and then at l=132 condition fails.

    // But the condition is checked at l=0 first.

    // Steps:
    //   l = 0 -> board[0]==13 -> body -> l=12
    //   l = 12 -> board[12]==13 -> body -> l=24
    //   ...
    //   l = 120 -> board[120]==13 -> body -> l=132
    //   now check board[132]: if not 13 -> exit
    // So body runs 12 times? Wait: from 0 to 120 inclusive, step 12: (120-0)/12+1 = 11 values? 
    // 0,12,24,36,48,60,72,84,96,108,120 -> 11 values -> 11 iterations of the body.

    // Then l becomes 132, condition fails.

    // But we can get one more by starting at negative?

    // bking_loc = -24 -> l starts at -12 -> board[-12] -> undefined behavior.

    // So minimum starting index is 0.

    // So best: bking_loc = -12 -> l starts at 0.

    // But is bking_loc=-12 acceptable? It's an integer, no restriction given.

    // So we set:
    bking_loc = -12;

    // Initialize all elements to 13
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Set the last element in the sequence to break the loop: at index 132
    // But note: the loop will check board[132] only after having incremented l to 132 from 120.
    // We want to avoid accessing beyond 143, so 132 is safe.
    // But we also don't want to run too many iterations? We want as many as possible within bounds.

    // The sequence starting at 0: 0,12,24,36,48,60,72,84,96,108,120,132 -> 12 indices.
    // We want the loop to run the body for the first 11 (until 120) and then at 132 fail.

    // But the condition is checked at every l value.

    // At l=132, we break.

    // So we set board[132] to a value != 13.
    board[132] = 0;

    // This way, the loop will iterate 12 times? Let's count:

    // Iteration 1: l = 0 -> board[0]==13 -> body -> l +=12 -> l=12
    // Iteration 2: l=12 -> board[12]==13 -> body -> l=24
    // ...
    // Iteration 11: l=120 -> board[120]==13 -> body -> l=132
    // Now check condition: board[132]==0 !=13 -> exit

    // So the body runs 11 times.

    // But we can do better? What if we set bking_loc=-12, and leave board[132]==13? Then:
    // After l=132, we do l+=12 -> l=144, then check board[144] -> out of bounds -> undefined behavior.

    // So we must break at 132.

    // Alternatively, set bking_loc to a value so that the sequence ends earlier but we have more data? No.

    // 11 iterations is the maximum we can safely have.

    // But note: we could have non-consecutive sequences? But the loop steps by 12.

    // We are constrained by memory layout.

    // So this is the best.

    // However, the requirement says "approximately 0.01 seconds", but 11 iterations is nanoseconds.

    // But the array size is fixed at 144, so we cannot meet the time requirement.

    // Given the constraint, we follow the array size and ensure safety.

    // Reset l to a safe initial value (though loop will overwrite it)
    l = 0;
}