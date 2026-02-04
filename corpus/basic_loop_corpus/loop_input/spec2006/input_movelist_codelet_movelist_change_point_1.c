#include <stdint.h>
#include <string.h>

int move;
int max_points;
int points[262144]; // 1MB of data (262144 integers * 4 bytes = ~1MB)
int k;

void init_vars() {
    move = 42;
    max_points = 262144;
    memset(points, 0, sizeof(points));
    points[max_points - 1] = move; // Ensure the value is found at the last position to maximize loop iterations
}