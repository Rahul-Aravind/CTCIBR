#include<iostream>
#include<cstdio>

using namespace std;

int matrix[2][2]= {{1,2},{3,4}};
int row=2,col=2;

void printMatrix(int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotateImage(int i, int j, int m, int n)
{
    if(i>m || j>n) return;

    int r=i;
    int c=i;
    for(int idx=r; idx< m; idx++)
    {
        int tmp = matrix[r][c+idx];
        matrix[r][c+idx] = matrix[m-idx][r];
        matrix[m-idx][r] = matrix[m][n-idx];
        matrix[m][n-idx] = matrix[r+idx][n];
        matrix[r+idx][n] = tmp;


    }

    rotateImage(i+1, j+1, m-1, n-1);
}

int main()
{

  cout<<"Matrix when its not rotated"<<endl;
  printMatrix(row,col);
  rotateImage(0,0,row-1,col-1);
  printMatrix(row,col);

  return 0;

}
