#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int matrix[4][4] = {{1,2,0,4},{5,7,8,9},{9,10,11,12},{13,14,15,16}};
int row = 4, col = 4;

void printMatrix(int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void nullifyRow(int rowIdx, int col)
{
    for(int i=0;i<col;i++)
        matrix[rowIdx][i]=0;
}

void nullifyCol(int row, int colIdx)
{
    for(int i=0;i<row;i++)
        matrix[i][colIdx]=0;
}

void setzeros(int m, int n)
{
    map<int, bool>row_map;
    map<int, bool>col_map;
    row_map.clear();
    col_map.clear();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                row_map[i]=true;
                col_map[j]=true;
            }
        }
    }

    //set entire row to zero if the element in that row is zero

    for(int i=0;i<m;i++)
    {
        if(row_map[i]==true)
            nullifyRow(i, col);
    }

    //set entire col to zero if the element in that col is zero

    for(int i=0;i<n;i++)
        if(col_map[i]==true)
            nullifyCol(row, i);
}

int main()
{
    printMatrix(row, col);
    setzeros(row, col);
    printMatrix(row, col);
}
