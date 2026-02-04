#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE test_index_array[5];
extern INT_TYPE test_rank_array[5];
extern INT_TYPE S_test_index_array[5];
extern INT_TYPE S_test_rank_array[5];
extern INT_TYPE W_test_index_array[5];
extern INT_TYPE W_test_rank_array[5];
extern INT_TYPE A_test_index_array[5];
extern INT_TYPE A_test_rank_array[5];
extern INT_TYPE B_test_index_array[5];
extern INT_TYPE B_test_rank_array[5];
extern INT_TYPE C_test_index_array[5];
extern INT_TYPE C_test_rank_array[5];
extern int i;



void loop(){
    for (i = 0; i < 5; i += 2) {
        switch ('A') {
          case 'S':
            test_index_array[i] = S_test_index_array[i] * 2;
            test_rank_array[i] = S_test_rank_array[i] * 2;
            if (i + 1 < 5) {
                test_index_array[i+1] = S_test_index_array[i+1] * 2;
                test_rank_array[i+1] = S_test_rank_array[i+1] * 2;
            }
            break;
          case 'A':
            test_index_array[i] = A_test_index_array[i] * 2;
            test_rank_array[i] = A_test_rank_array[i] * 2;
            if (i + 1 < 5) {
                test_index_array[i+1] = A_test_index_array[i+1] * 2;
                test_rank_array[i+1] = A_test_rank_array[i+1] * 2;
            }
            break;
          case 'W':
            test_index_array[i] = W_test_index_array[i] * 2;
            test_rank_array[i] = W_test_rank_array[i] * 2;
            if (i + 1 < 5) {
                test_index_array[i+1] = W_test_index_array[i+1] * 2;
                test_rank_array[i+1] = W_test_rank_array[i+1] * 2;
            }
            break;
          case 'B':
            test_index_array[i] = B_test_index_array[i] * 2;
            test_rank_array[i] = B_test_rank_array[i] * 2;
            if (i + 1 < 5) {
                test_index_array[i+1] = B_test_index_array[i+1] * 2;
                test_rank_array[i+1] = B_test_rank_array[i+1] * 2;
            }
            break;
          case 'C':
            test_index_array[i] = C_test_index_array[i] * 2;
            test_rank_array[i] = C_test_rank_array[i] * 2;
            if (i + 1 < 5) {
                test_index_array[i+1] = C_test_index_array[i+1] * 2;
                test_rank_array[i+1] = C_test_rank_array[i+1] * 2;
            }
            break;
        }
    }
}
