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
    for (i = 0; i < 10; i++) {
        int idx = i % 5;
        switch ('A') {
          case 'S':
            test_index_array[idx] = S_test_index_array[idx] + S_test_rank_array[idx];
            test_rank_array[idx] = S_test_rank_array[idx] - S_test_index_array[idx];
            break;
          case 'A':
            test_index_array[idx] = A_test_index_array[idx] + A_test_rank_array[idx];
            test_rank_array[idx] = A_test_rank_array[idx] - A_test_index_array[idx];
            break;
          case 'W':
            test_index_array[idx] = W_test_index_array[idx] + W_test_rank_array[idx];
            test_rank_array[idx] = W_test_rank_array[idx] - W_test_index_array[idx];
            break;
          case 'B':
            test_index_array[idx] = B_test_index_array[idx] + B_test_rank_array[idx];
            test_rank_array[idx] = B_test_rank_array[idx] - B_test_index_array[idx];
            break;
          case 'C':
            test_index_array[idx] = C_test_index_array[idx] + C_test_rank_array[idx];
            test_rank_array[idx] = C_test_rank_array[idx] - C_test_index_array[idx];
            break;
        }
    }
}
