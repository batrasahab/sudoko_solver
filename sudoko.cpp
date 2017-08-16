#include<iostream>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int no,int n){

    for(int x=0;x<n;x++){
        if(mat[i][x]==no || mat[x][j]==no ){
            return false;
        }
    }

    int sx = (i/3)*3;
    int sy = (j/3)*3;
    int x,y;

    for(x=sx;x<sx+3;x++){
        for(y=sy;y<sy+3;y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){

    if(i==n){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
                if((j+1)%3==0){
                    cout<<"   ";
                }

            }
            if((i+1)%3==0){
                cout<<endl;
            }
            cout<<endl;
        }

        return true;
    }
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    //Blue cell
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }
    //White cell
    for(int no=1;no<=9;no++){
        if(isSafe(mat,i,j,no,n)){

            mat[i][j] = no;
            bool solveAaageKa = solveSudoku(mat,i,j+1,n);
            if(solveAaageKa==true){
                return true;
            }
            //backtrack
            mat[i][j] = 0;

        }

    }
    return false;
}

int main(){

    int mat[9][9];
    int n=9;

    cout<<"ENTER THE SUDOKO GRID. INPLACE OF BLANK SPACES ENTER ZEROES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }

    cout<<"THE GRID ENTERED BY YOU IS"<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
                if((j+1)%3==0){
                    cout<<"   ";
                }

            }
            if((i+1)%3==0){
                cout<<endl;
            }
            cout<<endl;
        }

        cout<<endl;


    cout<<endl;
    cout<<"Solution - "<<endl;
    solveSudoku(mat,0,0,9);





    return 0;
}
