#include <stdio.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int width;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    // Set data size to target ~0.01 seconds runtime
    // The loop runs (maxx - ((width > x) ? width : x)) iterations
    // We choose values so that the loop processes about 64M elements for typical performance

    width = 0;
    x = 64 * 1024 * 16;  // 1M * 16 = 16M iterations
    maxx = x + 16 * 1024 * 1024;  // Ensure 16M iterations

    // Adjust line size is fixed at 16, so we must ensure i - x < 16
    // So i must be in [x, x+15] -> maxx should be x+16 at most
    // But original loop condition: i from max(width,x) to maxx (exclusive)

    // To avoid out-of-bounds on line[i-x], we require:
    // i - x < 16  => i < x + 16
    // So set maxx = x + 16

    width = 0;  // so max(width, x) = x
    x = 100;    // arbitrary base offset
    maxx = x + 16;  // exactly 16 iterations, i from x to x+15

    // Now line[i-x] goes from line[0] to line[15] -> safe

    // Picy[width-1]: if width=0, then index = -1 -> invalid
    // So set width >= 1

    width = 1;
    // Now Picy[width-1] = Picy[0]

    // Allocate and initialize Picy
    static unsigned short picy_storage[1];
    picy_storage[0] = 0xABCD;
    Picy = picy_storage;
}