#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with size 144 (12x12), as per declaration
    for (int i = 0; i < 144; i++) {
        board[i] = 13;  // Default value to satisfy loop condition
    }

    // Ensure that bking_loc is set so that bking_loc + 11 is within bounds
    // and allows several iterations before going out of bounds or changing value
    bking_loc = 10;  // So l starts at 21

    // Modify a location past a few steps to break the loop eventually
    // Loop steps by 11: l = bking_loc+11, then +11 each time
    // We want it to iterate roughly thousands/millions of times? But board only has 144 elements.
    // Since board is only 144 elements, we cannot have large data.

    // To avoid accessing out-of-bounds, we must break before l >= 144
    // l starts at bking_loc + 11 = 21, increments by 11
    // Max safe index is 143. So max l should be <= 143 -> max steps: (143 - 21) / 11 ≈ 11 steps

    // But we need loop to run ~0.01 seconds. A tight loop checking memory can do billions/sec?
    // However, only 144 elements — we can't scale array arbitrarily because declared size is fixed.

    // Important: the array is fixed size: 144. So we cannot make it larger.
    // Therefore, the loop will run at most around 12 iterations — too fast.

    // But requirement says: "suggest 1MB–256MB of input data unless the length is specified"
    // Here, length *is* specified: [144]. So we must respect that.

    // So we cannot change array size. Hence, the loop will be very fast (< 1 microsecond).
    // But requirement asks for ~0.01 seconds — impossible under fixed 144-size array.

    // Re-evaluate: maybe the 'board' in loop code is not the same as our board?
    // No — it's the same extern.

    // Conclusion: we must follow the declared size. The performance target cannot be met due to fixed small size.
    // So we initialize correctly and safely, even if runtime is short.

    // Set up so loop runs about 10 times then stops
    // l = 21, 32, 43, 54, 65, 76, 87, 98, 109, 120, 131, 142 -> next would be 153 (invalid)
    // So if all are 13, it will run 12 times and stop when l=142+11=153? No — condition checked at start.

    // The loop: for (l = bking_loc + 11; board[l] == 13; l += 11)
    // So when l reaches 142: board[142]==13 -> enter, then l becomes 153, then check board[153] -> out of bounds!

    // So we must break before l >= 144.

    // Therefore, set one element beyond some point to non-13 to break early.

    // Let’s allow 10 iterations:
    // Start: l0 = bking_loc + 11 = 10 + 11 = 21
    // Then 32, 43, 54, 65, 76, 87, 98, 109, 120, 131 -> next 142 is valid, then 153 invalid
    // So if we set board[142] != 13, then when l=131, it does l+=11 -> l=142, checks board[142] -> fails -> exit safely.

    // But wait: after incrementing l, it checks condition at top. So when l becomes 142, it checks board[142].
    // So we must ensure board[142] != 13 to break before using it.

    // So set board[142] = 0 to break the loop.
    board[142] = 0;

    // Also ensure bking_loc + 11 is in range: 10+11=21 < 144 → ok.
    // And all intermediate indices: 21,32,...,131 are <144 → ok.
    // Next would be 142 → valid index but value breaks loop.

    // Final state: loop runs 11 times? Let's trace:
    // l = 21 → board[21]==13 → continue
    // l = 32 → ... 
    // ...
    // l = 131 → board[131]==13 → continue
    // l +=11 → l=142 → check board[142]==0 → false → exit.

    // So 11 iterations.

    // This is safe and within bounds.

    // Reset bking_loc to 10 as above
    bking_loc = 10;

    // l will be modified by loop, no need to initialize here
}