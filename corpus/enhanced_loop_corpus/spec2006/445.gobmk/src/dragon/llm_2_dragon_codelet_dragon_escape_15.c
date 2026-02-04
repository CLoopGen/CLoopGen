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
    for (distance = 0; distance <= 4; distance++) {
        int save_queue_end = queue_end;
        for (int q_idx = queue_start; q_idx < save_queue_end; q_idx++) {
            ii = queue[q_idx];
            if ((color == 1 && ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)) || 
                (color == 2 && ((black_eye[ii].type & 4) || black_eye[ii].cut == 1))) {
                continue;
            }
            if (distance == 4) {
                escape_potential += escape_value[ii];
            } else {
                int offsets[4] = {19 + 1, -1, -(19 + 1), 1};
                for (int dir = 0; dir < 4; dir++) {
                    int pos = ii + offsets[dir];
                    if ((board[pos] != 3) && !mx[pos]) {
                        int valid = 0;
                        if (board[pos] == color) {
                            valid = 1;
                        } else if (board[pos] == 0) {
                            int p1 = pos + (dir == 0 ? 1 : (dir == 1 ? -(19 + 1) : (dir == 2 ? -1 : (19 + 1))));
                            int p2 = pos + 2 * offsets[dir];
                            int p3 = pos + (dir == 0 ? -1 : (dir == 1 ? -(19 + 1) : (dir == 2 ? 1 : (19 + 1))));
                            if ((board[p1] != 3) && board[p1] != other &&
                                (board[p2] != 3) && board[p2] != other &&
                                (board[p3] != 3) && board[p3] != other) {
                                valid = 1;
                            }
                        }
                        if (valid) {
                            queue[queue_end++] = pos;
                            mx[pos] = 1;
                        }
                    }
                }
                if (distance == 0) {
                    int diag_offsets[4] = {(19 + 1) - 1, -(19 + 1) - 1, -(19 + 1) + 1, (19 + 1) + 1};
                    int checks[4][2] = {{(19 + 1), -1}, {-1, -(19 + 1)}, {-(19 + 1), 1}, {1, (19 + 1)}};
                    for (int d = 0; d < 4; d++) {
                        int diag_pos = ii + diag_offsets[d];
                        if (board[ii + checks[d][0]] == 0 && board[ii + checks[d][1]] == 0 && !mx[diag_pos]) {
                            if (board[diag_pos] == color ||
                                (board[diag_pos] == 0 && 
                                 (board[diag_pos + (d == 0 ? (19 + 1) : (d == 1 ? -1 : (d == 2 ? -(19 + 1) : 1)))] != 3) &&
                                 board[diag_pos + (d == 0 ? (19 + 1) : (d == 1 ? -1 : (d == 2 ? -(19 + 1) : 1)))] != other &&
                                 (board[diag_pos + (d == 0 ? -1 : (d == 1 ? -(19 + 1) : (d == 2 ? 1 : (19 + 1))))] != 3) &&
                                 board[diag_pos + (d == 0 ? -1 : (d == 1 ? -(19 + 1) : (d == 2 ? 1 : (19 + 1))))] != other)) {
                                queue[queue_end++] = diag_pos;
                                mx[diag_pos] = 1;
                            }
                        }
                    }
                }
            }
        }
        queue_start = save_queue_end;
    }
}
