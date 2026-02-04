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



void loop(){
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
                int offset = 19 + 1;
                int pos_n, pos_e, pos_s, pos_w;
                int diag_ne, diag_nw, diag_sw, diag_se;

                pos_s = ii + offset;
                pos_w = ii - 1;
                pos_n = ii - offset;
                pos_e = ii + 1;

                diag_ne = ii + offset + 1;
                diag_nw = ii - offset - 1;
                diag_sw = ii - offset + 1;
                diag_se = ii + offset - 1;

                // Introduce WAW dependency by pre-marking mx updates before conditional enqueue
                if ((board[pos_s] != 3) && !mx[pos_s] && 
                    (board[pos_s] == color || 
                     (board[pos_s] == 0 && board[pos_s + 1] != 3 && board[pos_s + 1] != other &&
                      board[pos_s + offset] != 3 && board[pos_s + offset] != other &&
                      board[pos_s - 1] != 3 && board[pos_s - 1] != other))) {
                    mx[pos_s] = 1;
                    queue[queue_end++] = pos_s;
                }

                if ((board[pos_w] != 3) && !mx[pos_w] && 
                    (board[pos_w] == color || 
                     (board[pos_w] == 0 && board[pos_w + offset] != 3 && board[pos_w + offset] != other &&
                      board[pos_w - 1] != 3 && board[pos_w - 1] != other &&
                      board[pos_w - offset] != 3 && board[pos_w - offset] != other))) {
                    mx[pos_w] = 1;
                    queue[queue_end++] = pos_w;
                }

                if ((board[pos_n] != 3) && !mx[pos_n] && 
                    (board[pos_n] == color || 
                     (board[pos_n] == 0 && board[pos_n - 1] != 3 && board[pos_n - 1] != other &&
                      board[pos_n - offset] != 3 && board[pos_n - offset] != other &&
                      board[pos_n + 1] != 3 && board[pos_n + 1] != other))) {
                    mx[pos_n] = 1;
                    queue[queue_end++] = pos_n;
                }

                if ((board[pos_e] != 3) && !mx[pos_e] && 
                    (board[pos_e] == color || 
                     (board[pos_e] == 0 && board[pos_e - offset] != 3 && board[pos_e - offset] != other &&
                      board[pos_e + 1] != 3 && board[pos_e + 1] != other &&
                      board[pos_e + offset] != 3 && board[pos_e + offset] != other))) {
                    mx[pos_e] = 1;
                    queue[queue_end++] = pos_e;
                }

                if (distance == 0) {
                    if (board[pos_s] == 0 && board[pos_w] == 0 && !mx[diag_se] && 
                        (board[diag_se] == color || 
                         (board[diag_se] == 0 && board[diag_se + offset] != 3 && board[diag_se + offset] != other &&
                          board[diag_se - 1] != 3 && board[diag_se - 1] != other))) {
                        mx[diag_se] = 1;
                        queue[queue_end++] = diag_se;
                    }
                    if (board[pos_w] == 0 && board[pos_n] == 0 && !mx[diag_nw] && 
                        (board[diag_nw] == color || 
                         (board[diag_nw] == 0 && board[diag_nw - 1] != 3 && board[diag_nw - 1] != other &&
                          board[diag_nw - offset] != 3 && board[diag_nw - offset] != other))) {
                        mx[diag_nw] = 1;
                        queue[queue_end++] = diag_nw;
                    }
                    if (board[pos_n] == 0 && board[pos_e] == 0 && !mx[diag_sw] && 
                        (board[diag_sw] == color || 
                         (board[diag_sw] == 0 && board[diag_sw - offset] != 3 && board[diag_sw - offset] != other &&
                          board[diag_sw + 1] != 3 && board[diag_sw + 1] != other))) {
                        mx[diag_sw] = 1;
                        queue[queue_end++] = diag_sw;
                    }
                    if (board[pos_e] == 0 && board[pos_s] == 0 && !mx[diag_ne] && 
                        (board[diag_ne] == color || 
                         (board[diag_ne] == 0 && board[diag_ne + 1] != 3 && board[diag_ne + 1] != other &&
                          board[diag_ne + offset] != 3 && board[diag_ne + offset] != other))) {
                        mx[diag_ne] = 1;
                        queue[queue_end++] = diag_ne;
                    }
                }
            }
        }
        queue_start = save_queue_end;
    }
}
