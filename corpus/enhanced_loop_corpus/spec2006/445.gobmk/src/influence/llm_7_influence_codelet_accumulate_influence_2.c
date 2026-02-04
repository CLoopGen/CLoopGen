#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int deltai[8];
extern int deltaj[8];
extern int delta[8];
extern Intersection board[421];
extern  int permeability_array[400];
extern  char safe[400];
extern int ii;
extern int queue[400];
extern int d;
extern int b;
extern int queue_start;
extern int queue_end;
extern int working[400];
extern int current_strength;
extern int delta_i;
extern int delta_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Introduce WAW and WAR dependencies by reordering and introducing temporary accumulators
// Also unroll the loop partially to create artificial data dependencies across iterations

int temp_working[4] = {0};  // Local accumulation to introduce WAR/WAW
int temp_queue_additions[4];
int temp_queue_count = 0;

// Fully unroll the loop to eliminate loop-carried dependencies and allow explicit ordering
for (int unroll_d = 0; unroll_d < 4; unroll_d++) {
    int d = unroll_d;
    int addr = ii + delta[d];
    if (board[addr] == 3) continue;

    int dot_prod = deltai[d] * delta_i + deltaj[d] * delta_j;
    int should_process = (!safe[addr] && (dot_prod > 0 || queue_start == 1));

    if (!should_process) continue;

    int contrib = current_strength * permeability_array[ii] >> 12;

    if (queue_start != 1) {
        int scaled = dot_prod * dot_prod;
        contrib = (contrib * scaled) >> 12;
        contrib = (b * contrib) >> 12;
    }

    if (contrib <= ((int)(0.02 * (1<<12)) + 0.5)) continue;

    // Create WAR dependency: write before reading working[] in next "iteration"
    // Simulate loop-carried dependence by chaining through temp_working
    if (unroll_d > 0) {
        temp_working[unroll_d] = temp_working[unroll_d - 1] + contrib;  // Artificial WAW
    } else {
        temp_working[unroll_d] = contrib;
    }

    if (working[addr] == 0) {
        temp_queue_additions[temp_queue_count] = addr;
        temp_queue_count++;
    }
}

// Commit queued changes to break RAW hazards and simulate delayed update
for (int i = 0; i < temp_queue_count; i++) {
    int idx = temp_queue_additions[i];
    queue[queue_end] = idx;
    queue_end++;
}

// Final update to working array with accumulated values (WAW introduced)
for (int d = 0; d < 4; d++) {
    int addr = ii + delta[d];
    if (board[addr] != 3 && !safe[addr] && (deltai[d]*delta_i + deltaj[d]*delta_j > 0 || queue_start == 1)) {
        int contrib = (current_strength * permeability_array[ii]) >> 12;
        if (queue_start != 1) {
            int a = deltai[d]*delta_i + deltaj[d]*delta_j;
            contrib = (b * ((contrib * a * a) >> 12)) >> 12;
        }
        if (contrib > ((int)(0.02 * (1<<12)) + 0.5)) {
            working[addr] += temp_working[d];  // Use transformed value
        }
    }
}
}
