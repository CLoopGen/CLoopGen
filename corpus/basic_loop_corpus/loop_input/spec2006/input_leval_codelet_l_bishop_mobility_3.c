#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize board: set elements to 13 except at boundaries to prevent out-of-bounds
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Ensure that starting at `square + 13` and stepping by 13 stays within [0, 143]
    // Choose square such that l starts at a valid index and sequence remains in bounds
    // We want the loop to run for many iterations but not overflow
    // The longest chain stepping by 13 modulo 144 has period 144 / gcd(13,144) = 144
    // So we can have long runs. To control execution time (~0.01 sec), estimate iterations.

    // On modern CPU, ~1e8 operations/sec, 0.01 sec ≈ 1e6 simple operations.
    // Each loop iteration is a few operations; let's aim for ~500,000 iterations.

    // But our array is only 144 elements — cannot support large number of iterations.
    // Therefore, we must reinterpret: the data size constraint (1MB–256MB) suggests
    // that perhaps the array was meant to be larger? But declaration is fixed: board[144].

    // However, note: the problem says "suggest" unless length is specified.
    // Here, length *is* specified: 144. So we follow that.

    // With only 144 elements, maximum stride-13 sequence length is 144,
    // because indices: start, start+13, start+26, ... mod 144 cycle with period <= 144.

    // So maximum possible iterations is 144. That will run in << 0.01 seconds.
    // But requirement says "approximately 0.01 seconds", which may not be feasible.

    // We are constrained by array size. So we accept that runtime will be negligible,
    // but ensure correctness and no out-of-bounds.

    // Set square so that l = square + 13 is within bounds and stepping by 13 loops safely.

    // Let’s choose square = 0 -> l starts at 13.
    // Then sequence: 13, 26, 39, ..., up to less than 144.
    // How many steps? (144 - 13 - 1) / 13 = 130 / 13 = 10 full steps -> 10 iterations.

    // But we want as many as possible without UB.

    // Instead, we can set square such that the sequence wraps using modular arithmetic?
    // But the code does not do modular indexing — it uses raw addition.

    // So we must avoid exceeding 143 or going below 0.

    // The valid starting points for l are those where l + 13*k < 144 for k=0,1,...
    // Maximum k when starting at i: floor((143 - i) / 13)

    // To maximize iterations, minimize starting index.

    // But note: l starts at square + 13. So set square = -12 -> l = 1 -> then 1,14,27,... 
    // Let's compute: 1 + 13*k < 144 -> k < (143)/13 ≈ 10.99 -> k=0..10 -> 11 iterations.

    // Best: start at 0: l = 0? But l = square+13. So square = -13 -> l=0.
    // Then indices: 0,13,26,...,13*10=130, 13*11=143, 13*12=156 -> stop before 156.
    // So k from 0 to 11: 12 iterations.

    // So maximum 12 iterations.

    // We initialize to get 12 iterations.

    square = -13;
    m = 0;

    // Now set all elements along this path to 13 so the condition holds
    // Indices: 0,13,26,39,52,65,78,91,104,117,130,143
    // There are 12 indices.

    // But note: board[l] == 13 is the condition. We want it true until the last valid one.
    // At l=143: board[143]==13 -> enter loop, m++, then l +=13 -> l=156 -> next iteration checks board[156] -> out of bounds!

    // So we must break before accessing out-of-bounds.

    // The loop condition checks board[l] only when l is the current value.
    // So if l becomes 143, we check board[143], then m++, then l +=13 -> l=156.
    // Then next iteration: check board[156] -> undefined behavior.

    // Therefore, we must ensure that after incrementing l, if it would go out of bounds, the loop condition fails.

    // But the condition is on board[l], not on l itself.

    // So we must make sure that when l reaches an out-of-bounds value, we don't dereference.

    // But the loop structure:
    //   for (l = square + 13; board[l] == 13; l += 13)
    //       m++;
    //
    // First iteration: l is initialized to square+13 -> must be in [0,143]
    // Then board[l] is accessed -> must be valid.
    // Then m++.
    // Then l += 13 -> now l might be >=144.
    // Then condition: board[l] -> if l>=144 -> out of bounds.

    // So to prevent UB, we must break the chain before accessing invalid memory.

    // Solution: set one element in the chain to non-13 to break early.

    // We want to allow about 12 iterations? But we can't even safely do one if we step out.

    // Actually, the loop condition is checked at the beginning of each iteration, including the first.

    // Steps:
    //   l = square+13  --> l0
    //   check board[l0] == 13 --> must be in bounds
    //   if true: execute body (m++), then l +=13 -> l1
    //   then check board[l1] == 13

    // So the access is always at the current value of l, which is set either by initialization or by +=13.

    // Therefore, we must ensure that every value that l takes when evaluating the condition is in [0,143].

    // The sequence of l values during condition check: l0, l1, l2, ..., lk
    // where l0 = square+13, l1 = l0+13, ..., lk = l0 + k*13
    // and we require lk < 144.

    // The last value we can safely check is l such that l < 144.

    // So we need l0 + k*13 < 144.

    // We can have multiple iterations, but the condition access must be in bounds.

    // After the last increment, l may become >=144, but it won't be used if we break.

    // But the condition is checked at the start of each iteration, so the value of l used in board[l] must be valid.

    // Therefore, we can only have k such that l0 + k*13 < 144.

    // Example: l0 = 0 -> k max: 0 + k*13 < 144 -> k < 144/13 ≈ 11.07 -> k=0 to 11 -> 12 iterations.

    // At k=11: l = 0 + 11*13 = 143 -> valid -> check board[143] -> if 13, enter loop, m++, then l +=13 -> l=156.
    // Then next iteration: condition check uses l=156 -> board[156] -> out of bounds.

    // So we must break the chain so that the loop does not attempt to continue after l=143.

    // But we cannot control l's value — it's updated unconditionally.

    // Therefore, the only safe way is to ensure that board[156] is not accessed.

    // But 156 is out of bounds.

    // Hence, we must ensure that the loop body does not cause l to reach a value >=144 at the condition check.

    // So the maximum l we can have at condition check is 143.

    // And after we do l +=13, it becomes 156, but then the condition is checked again -> board[156] -> UB.

    // Therefore, to avoid UB, we must break the chain before that.

    // We can do that by setting one element to non-13.

    // For example, set board[143] = 0, so when l=143, the condition fails, and we don't do l+=13 after the body?

    // Let's trace:

    // Suppose we are at iteration where l=130 (valid), board[130]==13 -> enter body -> m++, then l +=13 -> l=143.
    // Next iteration: check board[143] -> if we set it to 0, then condition false -> exit loop -> never access board[156].

    // But wait: the l +=13 happens at the end of the loop body, then the condition is checked at the top of the next iteration.

    // So when l=143, we check board[143]. If it's not 13, we break, and l remains 143.

    // But 143 is still in bounds -> so board[143] access is valid.

    // Therefore, we can safely break at 143 by setting board[143] != 13.

    // But we want to maximize iterations.

    // Sequence of l at condition check: 0,13,26,...,130,143
    // That's 12 values: 0 + 13*0, 13*1, ..., 13*11 = 143.

    // We want the first 11 to be 13, and the last one (143) to be not 13, so that we do 11 full iterations.

    // But wait: when l=130, we enter the loop, m becomes 11, then l +=13 -> l=143.
    // Then next iteration: check board[143] -> not 13 -> break.
    // So m ends at 11.

    // But we could also break earlier.

    // Alternatively, we can arrange so that the initial l is 0, and we set board[0] to 13, board[13] to 13, ..., board[130] to 13, and board[143] to 0.

    // Then the loop will run for l=0,13,...,130: that's 11 values? Let's count:
    // 0,13,26,39,52,65,78,91,104,117,130 -> 11 values.

    // l starts at 0 -> check board[0]==13 -> true -> m=1, l=13
    // check board[13]==13 -> true -> m=2, l=26
    // ...
    // check board[130]==13 -> true -> m=11, l=143
    // check board[143]==0 -> false -> exit.

    // So m=11.

    // But we can get 12 iterations if we include 143? Only if we don't update l after that.

    // But the structure doesn't allow that.

    // So maximum safe iterations: 11.

    // But 11 iterations is very fast, but we have no choice.

    // Alternatively, we can make the chain shorter but repeat the loop many times? No, the function is called once.

    // Or, we can misunderstand the problem: maybe the array should be larger?

    // But the code says: extern int board[144]; so it must be 144.

    // Therefore, we proceed with safe initialization.

    square = -13; // so l starts at 0
    m = 0;

    // Set all elements in the sequence 0,13,26,...,130 to 13
    for (int idx = 0; idx <= 130; idx += 13) {
        board[idx] = 13;
    }
    // Set board[143] to something else to break the loop
    board[143] = 0;

    // Also, initialize other elements to avoid any unintended matches
    // But only the ones on the path matter; others are not accessed
    // But to be safe, we can set all to 0 except the ones we want
    // Already set the ones we want above, now set the rest?

    // But we already set specific ones. Let's reinitialize properly.

    // Reset: set all board to 0 first, then set the desired ones to 13
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }
    for (int idx = 0; idx <= 130; idx += 13) {
        board[idx] = 13;
    }
}