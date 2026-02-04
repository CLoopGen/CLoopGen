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
for (distance = 0; distance <= 5; distance++) {
    int save_queue_end = queue_end;
    for (; queue_start < save_queue_end; queue_start++) {
        ii = queue[queue_start];
        if ((color == 1 && ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)) || 
            (color == 2 && ((black_eye[ii].type & 4) || black_eye[ii].cut == 1)))
            continue;
        if (distance >= 4) {
            escape_potential += escape_value[ii];
        } else {
            int deltas[] = {19 + 1, -1, -(19 + 1), 1};
            for (int d = 0; d < 4; d++) {
                int pos = ii + deltas[d];
                if ((board[pos] != 3) && !mx[pos]) {
                    int cond = (board[pos] == color);
                    if (!cond && board[pos] == 0) {
                        int n1 = pos + (deltas[d] == (19 + 1) ? 1 : (deltas[d] == -1 ? -(19 + 1) : (deltas[d] == -(19 + 1) ? -1 : (19 + 1))));
                        int n2 = pos + (deltas[d] == (19 + 1) ? (19 + 1) : (deltas[d] == -1 ? -1 : (deltas[d] == -(19 + 1) ? -(19 + 1) : 1)));
                        int n3 = pos + (deltas[d] == (19 + 1) ? -1 : (deltas[d] == -1 ? (19 + 1) : (deltas[d] == -(19 + 1) ? 1 : -(19 + 1))));
                        cond = (board[n1] != 3 && board[n1] != other &&
                                board[n2] != 3 && board[n2] != other &&
                                board[n3] != 3 && board[n3] != other);
                    }
                    if (cond) {
                        queue[queue_end++] = pos;
                        mx[pos] = 1;
                    }
                }
            }
            if (distance == 0) {
                int corners[] = {(19 + 1) - 1, -(19 + 1) - 1, -(19 + 1) + 1, (19 + 1) + 1};
                for (int c = 0; c < 4; c++) {
                    int offset = corners[c];
                    int pos = ii + offset;
                    if (!((offset == (19 + 1) - 1 && (board[ii + (19 + 1)] != 0 || board[ii - 1] != 0)) ||
                          (offset == -(19 + 1) - 1 && (board[ii - 1] != 0 || board[ii - (19 + 1)] != 0)) ||
                          (offset == -(19 + 1) + 1 && (board[ii - (19 + 1)] != 0 || board[ii + 1] != 0)) ||
                          (offset == (19 + 1) + 1 && (board[ii + 1] != 0 || board[ii + (19 + 1)] != 0))))
                        continue;
                    if (!mx[pos] && (board[pos] == color || 
                         (board[pos] == 0 && 
                          board[pos + (offset == (19 + 1) - 1 ? (19 + 1) : (offset == -(19 + 1) - 1 ? -1 : (offset == -(19 + 1) + 1 ? -(19 + 1) : 1)))] != 3 &&
                          board[pos + (offset == (19 + 1) - 1 ? (19 + 1) : (offset == -(19 + 1) - 1 ? -1 : (offset == -(19 + 1) + 1 ? -(19 + 1) : 1)))] != other &&
                          board[pos + (offset == (19 + 1) - 1 ? -1 : (offset == -(19 + 1) - 1 ? -(19 + 1) : (offset == -(19 + 1) + 1 ? 1 : (19 + 1))))] != 3 &&
                          board[pos + (offset == (19 + 1) - 1 ? -1 : (offset == -(19 + 1) - 1 ? -(19 + 1) : (offset == -(19 + 1) + 1 ? 1 : (19 + 1))))] != other))) {
                        queue[queue_end++] = pos;
                        mx[pos] = 1;
                    }
                }
            }
        }
    }
}
}
