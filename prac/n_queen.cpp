#include <bits/stdc++.h>
using namespace std;
int n;

void printSol(vector<vector<int>> board){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isSafe(int row,int col, vector<bool> row_check,vector<bool> left_diagonal,vector<bool> right_diagonal){
	if(row_check[row]==true || left_diagonal[row+col]==true || right_diagonal[col-row+n-1]==true){
		return false;
	}
	return true;
}

bool solve(vector<vector<int>>& board,int col,vector<bool> row_check,vector<bool> left_diagonal,vector<bool> right_diagonal){
	if(col>=n){
		return true;
	}

	for(int i=0;i<n;i++){

		if(isSafe(i,col,row_check,left_diagonal,right_diagonal)){
			row_check[i]=true;
			left_diagonal[i+col]=true;
			right_diagonal[col-i+n-1]=true;
			board[i][col]=1;

			if(solve(board,col+1,row_check,left_diagonal,right_diagonal)){
				return true;
			}

			row_check[i]=false;
			left_diagonal[i+col]=false;
			right_diagonal[col-i+n-1]=false;
			board[i][col]=0;

		}
	}
	return false;
}


int main(){

	cout<<"Enter the board size = ";
	cin>>n;

	vector<vector<int>> board(n,vector<int> (n,0));

	vector<bool> row_check(n, false);
	vector<bool> left_diagonal(2*n-1,false);
	vector<bool> right_diagonal(2*n-1,false);

	bool ans = solve(board , 0, row_check,left_diagonal,right_diagonal);

	if(ans == true){

		printSol(board);
	}
	else{
		cout<<"Solution Does not Exist\n";
	}

}