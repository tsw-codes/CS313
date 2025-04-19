#include <stdio.h>

int main() {
   
    int a[2][2] = {
        {6, 4},
        {8, 3}
    };
    int b[2][3] = {
            {1,2 ,3 },
            {4,5, 6}
    };

    int c[2][3] = {
        {2, 4, 6},
        {1, 3, 5}
    };

    int b_scaled[2][3];
     for (int i = 0; i < 2; i++){
        for(int j = 0; j <3; j++){
            b_scaled[i][j] = 3 * b[i][j];
        }
     }
    int transposed[3][2];
      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++){
            transposed[j][i] = c[i][j];
        }
      }
    int multiply[2][2] = {{0}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++){
                multiply[i][j]  += b_scaled[i][k] * transposed[k][j];
            }
        }
    }
    int d[2][2];
    for(int i = 0; i <2; i++){
        for(int j = 0; j < 2; j++){
            d[i][j] = a[i][j] + multiply[i][j];
        }
    }
    printf("D = A + (3 * B x C^t) : \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}