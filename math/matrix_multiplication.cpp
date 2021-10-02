#include<iostream>
using namespace std;

struct matrix{
	int mat[2][2];
};

// Matrix multiplication
matrix mul(matrix A, matrix B){
	matrix C;

	for(int row=0; row<2; row++){
		for(int col=0; col<2; col++){
			int sm=0;
			for(int i=0; i<2; i++)
				sm += A.mat[row][i] * B.mat[i][col];
			C.mat[row][col]=sm;
		}
	}
	return C;
}

// return identitiy matrix
matrix identitiy(){
	matrix M;
	M.mat[0][0]=1, M.mat[0][1]=0;
	M.mat[1][0]=0, M.mat[1][1]=1;

	return M;
}

// return matrix power
matrix power(matrix A, int p){
	if(p==0)
		return identitiy();

	matrix M = power(A, p/2);

	if(p%2==0)
		return mul(M, M);
	else
		return mul(A, mul(M, M));
}

// return nth fibonacci nubmber (0th, 1st, 2nd ..) (O(log(n)))
int get_nth_fibonacci(int n){
	matrix fib;
	fib.mat[0][0]=1, fib.mat[0][1]=1;
	fib.mat[1][0]=1, fib.mat[1][1]=0;

	return power(fib, n).mat[0][0];
}

int main(){
	freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);

	matrix M;	 
	M.mat[0][0]=2, M.mat[0][1]=3;
	M.mat[1][0]=3, M.mat[1][1]=4;

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<M.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	// matrix ans = mul(M, M);
	matrix ans = power(M, 3);
	cout<<"After\n";
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<ans.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	// O(lon(n))
	cout<<"nth fibonacci number: "<<get_nth_fibonacci(700)<<endl;
}