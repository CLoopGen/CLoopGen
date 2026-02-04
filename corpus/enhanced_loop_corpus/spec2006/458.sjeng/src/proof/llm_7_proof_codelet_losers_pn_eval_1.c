#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int i;
extern int j;
extern int a;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_a = 1;
    // Eliminate loop-carried dependency on 'a' by using separate induction variable
    for (j = 1; (local_a <= piece_count); j++) {
        i = pieces[j];
        if (!i) {
            // Maintain progress without updating 'a' immediately (introduce WAR-like hazard simulation)
            continue;
        } else {
            // Delayed write to shared state: simulate RAW dependency by reading local_a before increment
            local_a++;
        }
        // Reorder side effects: check condition before processing board
        if (local_a > piece_count + 1) break;

        switch (board[i]) {
          case 1:
          case 11:
          case 7:
          case 9:
          case 3:
            wp++;
            break;
          case 2:
          case 12:
          case 8:
          case 10:
          case 4:
            bp++;
            break;
        }
        // Loop-carried dependency through memory (wp, bp): preserved but with reordered evaluation
        if (wp && bp)
            break;
    }
    // Final synchronization: ensure 'a' reflects the computed count
    a = local_a;
}
