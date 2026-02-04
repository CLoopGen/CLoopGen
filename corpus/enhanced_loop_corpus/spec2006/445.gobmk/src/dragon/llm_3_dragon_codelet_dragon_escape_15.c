#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};


extern Intersection board[421];
extern struct eye_data white_eye[400];
extern struct eye_data black_eye[400];
extern int color;
extern char escape_value[400];
extern int ii;
extern int mx[400];
extern int queue[361];
extern int queue_start;
extern int queue_end;
extern int other;
extern int distance;
extern int escape_potential;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    const int stride = 19 + 1;
    int access_pattern[8] = {stride, -1, -stride, 1, stride - 1, -stride - 1, -stride + 1, stride + 1};
    int base_checks[8][3] = {
        {stride, stride + 1, 2 * stride},           // down
        {-1, stride - 1, -2},                       // left
        {-stride, -stride - 1, -2 * stride},        // up
        {1, -stride + 1, 2},                        // right
        {stride, -1, 0},                            // down-left corner
        {-1, -stride, 0},                           // up-left corner
        {-stride, 1, 0},                            // up-right corner
        {1, stride, 0}                              // down-right corner
    };

    for (distance = 0; distance <= 4; distance++) {
        int save_queue_end = queue_end;
        for (int idx = queue_start; idx < save_queue_end; ++idx) {
            ii = queue[idx];
            int skip = 0;
            if (color == 1) {
                if ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)
                    skip = 1;
            } else if (color == 2) {
                if ((black_eye[ii].type & 4) || black_eye[ii].cut == 1)
                    skip = 1;
            }
            if (skip) continue;

            if (distance == 4) {
                escape_potential += escape_value[ii];
            } else {
                for (int step = 0; step < 4; step++) {
                    int pos = ii + access_pattern[step];
                    if (board[pos] == 3 || mx[pos]) continue;

                    int cond = 0;
                    if (board[pos] == color) {
                        cond = 1;
                    } else if (board[pos] == 0) {
                        int n1 = pos + base_checks[step][0];
                        int n2 = pos + base_checks[step][1];
                        int n3 = pos + base_checks[step][2];
                        if (board[n1] != 3 && board[n1] != other &&
                            board[n2] != 3 && board[n2] != other &&
                            board[n3] != 3 && board[n3] != other) {
                            cond = 1;
                        }
                    }

                    if (cond) {
                        queue[queue_end] = pos;
                        mx[pos] = 1;
                        queue_end++;
                    }
                }

                if (distance == 0) {
                    for (int step = 4; step < 8; step++) {
                        int pos = ii + access_pattern[step];
                        if (mx[pos]) continue;

                        int b1 = ii + base_checks[step][0];
                        int b2 = ii + base_checks[step][1];
                        if (board[b1] != 0 || board[b2] != 0) continue;

                        if (board[pos] == color) {
                            queue[queue_end] = pos;
                            mx[pos] = 1;
                            queue_end++;
                        } else if (board[pos] == 0) {
                            int n1 = pos + (step == 4 ? stride : (step == 5 ? -1 : (step == 6 ? -stride : 1)));
                            int n2 = pos + (step == 4 ? -1 : (step == 5 ? -stride : (step == 6 ? 1 : stride)));
                            if (board[n1] != 3 && board[n1] != other &&
                                board[n2] != 3 && board[n2] != other) {
                                queue[queue_end] = pos;
                                mx[pos] = 1;
                                queue_end++;
                            }
                        }
                    }
                }
            }
        }
        queue_start = save_queue_end;
    }
}
