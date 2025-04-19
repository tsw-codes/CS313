#include <iostream>
#include <vector>
using namespace std;

class matrix
{
    public:
    matrix(){
       
        a[0][0]  = 6; 
        a[0][1] = 4;
        a[1][0] = 8;
        a[1][1] =3; 

       
        b[0][0] = 1;
        b[0][1] = 2;
        b[0][2] = 3;
        b[1][0] = 4;
        b[1][1] = 5;
        b[1][2] = 6;

        
        c = {
            {2, 4, 6},
            {1, 3, 5}
        };

        d = vector<vector<int>>(2, vector<int>(2));

    }

    void computeMatrix() {
      

        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                b[i][j] = 3 * b[i][j];
            }
        }

       vector<vector<int>>temp(c[0].size(), vector<int>(c.size()));
        for (int i = 0; i < c.size(); i++){
            for(int j = 0; j < c[0].size(); j++){
                temp[j][i] = c[i][j];

            }
        }

        c = temp;

        vector<vector<int>>tempMat(2, vector<int>(2,0));
        for (int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; j++){
                for(int x = 0; x < 3; x++){
                    tempMat[i][j] += b[i][x] * temp[x][j];
                }
            }
        }

        for (int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                d[i][j] = a[i][j] + tempMat[i][j];
            }
        }


    }

    void printMatrix(int m[][3], int row, int col){
        for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++) {
              cout << m[i][j] << " ";
           }
           cout << endl;
        }
       
    }

    void printVec( vector<vector<int>> mat){
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[0].size(); j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    

    
    int a[2][2];
    int b[2][3];
    vector<vector<int>> c;
    vector<vector<int>> d;
    // int **mat;
    // int row;
    // int col;
};

int main(){
    matrix m;
    m.computeMatrix();

    m.printVec(m.d);
    return 0;
}