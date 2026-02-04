#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize the board array
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to satisfy the loop condition
    }

    // Ensure that starting at `square + 11` and stepping by 11 stays within bounds
    // We want the loop to run for a significant number of iterations but avoid overflow
    // To control runtime (~0.01 sec), we estimate iterations: modern CPU does ~1e9 ops/sec, so ~1e7 ops in 0.01s
    // The loop is very simple (one comparison, one increment), so we aim for ~1e6 to 1e7 iterations

    // However, our board size is fixed at 144, so we cannot exceed it.
    // Max index accessed: l = square + 11 + 11*k < 144
    // So k < (144 - square - 11)/11 = (133 - square)/11
    // To maximize k, set square as low as possible such that square + 11 >= 0

    // Let's set square = 0 -> l starts at 11, then 22, 33, ..., up to 132 (valid), next 143 valid, next 154 invalid
    // Indices: 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143 -> 13 iterations only.

    // But 13 iterations is too few. We cannot change the board size (fixed at 144).
    // Therefore, we cannot achieve 0.01 seconds with this loop unless we change interpretation.

    // Re-examining: the problem says "suggest 1MB–256MB of input data unless the length is specified"
    // But here, board is declared as [144], so length *is* specified.

    // So we must respect board[144]. Thus, maximum possible iteration count is about 13 per start.

    // However, note: `square` can be negative? As long as square+11 >= 0 and within bounds.

    // But the loop runs: for (l = square + 11; board[l] == 13; l += 11) m++;
    // So if we set square = -11, then l starts at 0 -> then 11, 22, ... until 143
    // Sequence: 0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143 -> 14 elements? 
    // But 143 is valid (index < 144). Next would be 154 -> invalid.

    // How many multiples of 11 from 0 to 143 inclusive?
    // 0, 11, 22, ..., 143 -> 143/11 = 13 -> 14 elements (including 0)

    // So maximum 14 iterations.

    // But we cannot make it longer without changing the array size.

    // Since the array size is fixed at 144, we accept that the loop will run only ~14 iterations.
    // This will take nanoseconds, not 0.01 seconds. But we cannot change the array.

    // Therefore, the performance target cannot be met without violating the declared size.

    // We follow the specification: array size is 144, so we use that.

    // Initialize square to -11 so that l starts at 0
    square = -11;

    // Initialize m to 0
    m = 0;

    // All board elements are already set to 13, so the loop condition holds until out of valid indices
    // But we must ensure we don't access board[l] when l >= 144
    // The loop condition checks board[l] only when l is in range? No, it doesn't check bounds.

    // So we must ensure that the loop stops before l >= 144.

    // Currently, if we start at 0 and go by 11, the last valid is 143 (11*13), next 154 -> out of bounds.

    // But the loop condition accesses board[l] without checking index bounds -> undefined behavior.

    // To prevent out-of-bounds access, we must break the chain before l reaches 144.

    // Solution: set one element beyond the intended sequence to non-13 to stop the loop naturally.

    // But we want to run as long as l is in bounds. So we let it run while l < 144.

    // The last l value that is valid is 143. After that, l becomes 154, but we never access board[154] if we break earlier.

    // However, the loop condition checks board[l] at the beginning of each iteration, including when l might be out of bounds.

    // Therefore, we must ensure that the loop terminates before l >= 144.

    // We can break the chain by setting one element to non-13 just before going out of bounds.

    // But we want maximum iterations within bounds.

    // Instead, we adjust the board so that when l reaches a value >= 144, the loop won't be entered.

    // But the condition is checked first: so when l=154, we would access board[154] -> invalid.

    // Therefore, we must ensure that the loop stops when l=143 (last valid), so that next increment makes l=154, but then the condition isn't checked because we break on bounds?

    // No, the structure is:
    //   l = square + 11  --> l = 0
    //   while (board[l] == 13) { m++; l += 11; }
    // So after l=143, we do l += 11 -> l=154, then check board[154] -> out of bounds.

    // Therefore, we must break the chain at or before the last valid index.

    // Let’s set board[143] to something other than 13? But 143 is 11*13, which is within [0,143].

    // But we want to include 143? Then we need to avoid accessing beyond.

    // Alternative: do not rely on bound check — instead, ensure that the starting point and step lead to termination within bounds.

    // But we have no control over the loop logic.

    // The only safe way: make sure that before l reaches an out-of-bounds index, the condition fails.

    // So we set one element in the diagonal to non-13 at the last position.

    // But we want as many iterations as possible.

    // Plan:
    //   Set all board[i] = 13 for i in the sequence 0, 11, 22, ..., 132
    //   Set board[143] = 0 (or any non-13) so that when l=143, the condition fails and we don't continue to increment and recheck?
    //   But wait: the sequence is: start at 0 -> valid, then 11, 22, ..., 132, then next is 143.
    //   When l=132: m++ and l becomes 143.
    //   Then check board[143] -> if it's not 13, loop ends. And 143 is valid index.

    // So we can safely set board[143] = 0.

    // But 143 = 11*13 = 143, which is < 144 -> valid.

    // So we set:
    //   for all i such that i % 11 == 0 and i <= 132, set board[i] = 13
    //   set board[143] = 0

    // But note: the starting point is l = square + 11 = -11 + 11 = 0.

    // The sequence: 0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143

    // We want the loop to stop at 143, so set board[143] != 13.

    // But what about other indices? They are not accessed, so we can leave them arbitrary.

    // However, we initially set all to 13. Now we fix:

    // Reset all to 0 first, then set the ones we need.
    for (int i = 0; i < 144; ++i) {
        board[i] = 0;
    }
    // Set every 11th element starting from 0 up to 132 to 13
    for (int i = 0; i <= 132; i += 11) {
        board[i] = 13;
    }
    // board[143] remains 0 -> stops the loop

    // Now the loop will run for values: 0,11,...,132 -> how many?
    // i=0,11,22,...,132 -> n terms: (132-0)/11 + 1 = 12 + 1 = 13 iterations.

    square = -11;  // so l starts at 0
    m = 0;
}