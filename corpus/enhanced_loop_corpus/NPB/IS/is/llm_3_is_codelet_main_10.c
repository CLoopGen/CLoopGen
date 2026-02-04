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
int indices[5] = {4, 1, 3, 0, 2};
for (i = 0; i < 5; i++)
    switch ('A') {
      case 'S':
        test_index_array[i] = S_test_index_array[indices[i]];
        test_rank_array[i] = S_test_rank_array[indices[i]];
        break;
      case 'A':
        test_index_array[i] = A_test_index_array[indices[i]];
        test_rank_array[i] = A_test_rank_array[indices[i]];
        break;
      case 'W':
        test_index_array[i] = W_test_index_array[indices[i]];
        test_rank_array[i] = W_test_rank_array[indices[i]];
        break;
      case 'B':
        test_index_array[i] = B_test_index_array[indices[i]];
        test_rank_array[i] = B_test_rank_array[indices[i]];
        break;
      case 'C':
        test_index_array[i] = C_test_index_array[indices[i]];
        test_rank_array[i] = C_test_rank_array[indices[i]];
        break;
    }
}
