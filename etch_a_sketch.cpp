#include "iostream"
#include "cstdlib"
#include "stdlib.h"
// #include "conio.h"

using namespace std;

void print_matrix(char** matrix , int a , int b){
	cout<<endl;
	for (int i = 0; i < a; ++i){
		for (int j = 0; j < b; ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int m,n,x,y;
	cout << "Enter the size of screen M rows x N cols\nRows : ";
	cin>>m;
	cout << "\nCols : ";
	cin >> n;
	char** matrix = new char*[m+2];
	for (int i = 0; i < (m+2); ++i){
		matrix[i] = new char[n+2];
	}

	for (int i = 0; i < m+2; ++i){
		for (int j = 0; j < n+2; ++j){
			matrix[i][j] ='.';
		}
	}
	print_matrix(matrix , m+2 , n+2);

	cout <<"Initialise the position\nEnter row no. followed by col no.\n";
	cin>>x>>y;
	while(1){
		if(x>=(m+1) || y>=(n+1) || x<1 || y<1){
			cout <<"Wrong I/p\nRe-enter the values of x and y\n";
			cin>>x>>y;
		}
		else
			break;
	}

	matrix[x][y] ='x';
	print_matrix(matrix , m+2 , n+2);
	char p;
	do{
		cout<<"Enter d to move right\nEnter a to move left\nEnter w to move up\nEnter s to move down\nEnter q to quit\nEnter c to clear screen\n";
		// p = getche();
		cin >>p;
		switch(p){
			case 'd':
				if((y+1) < (n+1) && y>0) matrix[x][++y] = 'x';
				else cout <<"\nWrong I/p\n";
				break;
			case 'a':
				if((y-1) > 0 && (y-1)<(n+1))matrix[x][--y] = 'x';
				else cout <<"\nWrong I/p\n";
				break;
			case 'w':
				if((x-1) > 0 && (x-1)< (m+1))matrix[--x][y] = 'x';
				else cout <<"\nWrong I/p\n";
				break;
			case 's':
				if((x+1) < (m+1) && x>0)matrix[++x][y] = 'x';
				else cout <<"\nWrong I/p\n";
				break;
			case 'c':
				for (int i = 0; i < m+2; ++i){
					for (int j = 0; j < n+2; ++j){
						matrix[i][j] ='.';
					}
				}
				print_matrix(matrix , m+2 , n+2);
				cout <<"Initialise the position\nEnter row no. followed by col no.\n";
				cin>>x>>y;
				while(1){
					if(x>=(m+1) || y>=(n+1) || x<1 || y<1){
						cout <<"Wrong I/p\nRe-enter the values of x and y\n";
						cin>>x>>y;
						break;
					}
					else
						break;
				}
				matrix[x][y] ='x';
				print_matrix(matrix , m+2 , n+2);
				break;
			default:
				cout << "Wrong Input\nPlay it carefully pal\n";
		}	
		print_matrix(matrix , m+2 , n+2);
		cout << "\n\nCurrent position -> Row : "<<x<<" Col : "<<y<<endl<<endl;
	}while(p != 'q');
} 