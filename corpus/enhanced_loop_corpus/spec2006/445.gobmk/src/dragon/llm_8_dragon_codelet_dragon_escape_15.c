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
for (distance = 0; distance <= 6; distance++) {
    int save_queue_end = queue_end;
    for (int q_idx = queue_start; q_idx < save_queue_end; q_idx++) {
        ii = queue[q_idx];
        if ((color == 1 && ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)) || 
            (color == 2 && ((black_eye[ii].type & 4) || black_eye[ii].cut == 1))) {
            continue;
        }
        if (distance == 6) {
            escape_potential += escape_value[ii] * 2;
        } else {
            int offsets[4] = {20, -1, -20, 1};
            for (int i = 0; i < 4; i++) {
                int pos = ii + offsets[i];
                if ((board[pos] != 3) && !mx[pos]) {
                    int valid = 0;
                    if (board[pos] == color) {
                        valid = 1;
                    } else if (board[pos] == 0) {
                        int n1 = pos + offsets[(i+1)%4], n2 = pos + offsets[(i+3)%4], n3 = pos + offsets[i]*2;
                        if (board[n1] != 3 && board[n1] != other &&
                            board[n2] != 3 && board[n2] != other &&
                            board[n3] != 3 && board[n3] != other) {
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
                int diag_offsets[4] = {19, -21, -19, 21};
                int cond_pairs[4][2] = {{20, -1}, {-1, -20}, {-20, 1}, {1, 20}};
                for (int d = 0; d < 4; d++) {
                    if (board[ii + cond_pairs[d][0]] == 0 && 
                        board[ii + cond_pairs[d][1]] == 0) {
                        int diag_pos = ii + diag_offsets[d];
                        if (!mx[diag_pos] && (board[diag_pos] == color || 
                            (board[diag_pos] == 0 && 
                             board[diag_pos + offsets[(d+1)%4]] != 3 && board[diag_pos + offsets[(d+1)%4]] != other &&
                             board[diag_pos + offsets[(d+3)%4]] != 3 && board[diag_pos + offsets[(d+3)%4]] != other))) {
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
