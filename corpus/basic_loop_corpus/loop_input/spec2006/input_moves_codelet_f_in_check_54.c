#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with size 144 as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop progression
    }

    // Ensure that bking_loc is set such that l starts at a valid index
    // l = bking_loc + 13 must be within [0, 143]
    // Also, we need to prevent infinite loop by setting a sentinel value at some point
    // Let's set bking_loc so that initial l is 0, meaning bking_loc = -13
    bking_loc = -13;

    // But then l starts at 0. We want the loop to run multiple times but terminate before OOB.
    // Modify one element beyond the expected traversal to break the loop.
    // Suppose we want the loop to run about 10 million iterations -> too big for 144 size.
    // Instead, since board is only 144 elements, the maximum chain is limited.

    // Adjust: We cannot have more than ~10 steps in steps of 13 within 144
    // Reset strategy: make most of the board 13, but set a non-13 value at last accessible index
    // Sequence: l = bking_loc+13, then +=13 each time
    // Choose bking_loc = 0 → l starts at 13
    bking_loc = 0;

    // Now l starts at 13
    // Set all elements along the path l=13,26,39,... to 13 until near end
    int idx;
    for (idx = 13; idx < 144; idx += 13) {
        board[idx] = 13;
    }
    // Set the next one beyond or last one to break condition
    if (idx < 144) {
        board[idx] = 0;
    } else {
        // Wrap around effect not needed; just break at last valid in sequence
        // Find last index in sequence below 144
        idx -= 13;
        // Force termination after reaching this one by making next out of bounds safe
        // But we don't write past 144. So ensure loop stops naturally.
        // Actually, when l becomes >=144, accessing board[l] is UB.
        // So we must ensure loop terminates before l reaches 144.
        // Therefore, set the element at the last safe step to 13, and the next logical step would be out of bounds,
        // but we must avoid accessing it. So we rely on the condition check only when l < 144.
        // However, the code does not check bounds — so we must terminate the loop via value before OOB.
    }

    // Rewriting safe initialization:
    // Pick bking_loc so that l starts at a safe position and allows several iterations
    // Let’s set bking_loc = 1 → l starts at 14
    // Then l: 14, 27, 40, 53, 66, 79, 92, 105, 118, 131, 144 (stop before 144)
    // 131 + 13 = 144 → which is out of bounds (valid indices 0..143)
    // So set board[131] = 13, but do not access board[144]

    // We need the loop to terminate when l reaches 144? No, because board[144] is invalid.
    // Therefore, we must break the loop before l goes out of bounds.
    // So set one of the values in the sequence to non-13 before the last.

    // Final plan:
    bking_loc = 1;  // so l starts at 1+13 = 14

    // Clear entire board first
    for (int i = 0; i < 144; ++i) {
        board[i] = 0;
    }

    // Fill every 13th element starting from 14 with 13, but stop before last few
    // Sequence: 14, 27, 40, 53, 66, 79, 92, 105, 118, 131
    // 131 + 13 = 144 → invalid → must break loop before incrementing to 144
    // So we want the loop body to execute for l=14,27,...,131, then at next iteration check fails?
    // But the condition is checked at the beginning of each iteration including the first.
    // After l=131, we do l += 13 → l=144, then check board[144] → undefined behavior.

    // To prevent this, we must break the chain earlier.
    // Set board[131] to something other than 13 so that when l=131, the condition fails and loop exits without incrementing again.
    // But wait: the loop structure:
    //   for (l = bking_loc + 13; board[l] == 13; l += 13)
    //       ;
    // Steps:
    //   l = 14
    //   check board[14] == 13 → true
    //   then body (empty)
    //   then l += 13 → l=27
    //   check board[27]==13 → true
    //   ...
    //   l = 118 → check → true → then l +=13 → l=131
    //   check board[131]==13 → if true → then l +=13 → l=144 → next check: board[144] → UB

    // Therefore, we must ensure that board[131] != 13 so that after l=118, we do l+=13→131, then check fails and exit.

    // So fill up to 118:
    for (int pos = 14; pos <= 118; pos += 13) {
        board[pos] = 13;
    }
    // Leave board[131] = 0 (already zero)

    // This way:
    // l starts at 14 → board[14]==13 → enter → l=27
    // ... → l=118 → board[118]==13 → enter → l=131
    // now check board[131] == 13? false → exit
    // l remains 131

    // Number of iterations: from 14 to 118 inclusive step 13: (118-14)/13 + 1 = (104)/13 +1 = 8+1=9 increments
    // But the loop runs the increment 9 times? Let's count:
    // Initial: l=14 → test → true → increment to 27
    // l=27 → test → true → inc to 40
    // l=40 → ... → inc to 53
    // 53 → inc to 66
    // 66 → inc to 79
    // 79 → inc to 92
    // 92 → inc to 105
    // 105 → inc to 118
    // 118 → test → true → inc to 131
    // Then test board[131] → false → exit
    // So l becomes 131 at the end.

    // This is safe and avoids out-of-bounds access.

    // Reinitialize bking_loc properly
    bking_loc = 1;

    // l will be modified by loop, no need to initialize here for correctness
}