#include<iostream>
using namespace std;
void solve();
void find_permutation(int a[], int left, long long int i, int length, int clen);
long long int recv(int n);
void swap(int *a, int num1, int num2);
int* rearrange_array(int a[], int left, int i, int n);

int main() {
	char c;
	cin >> c;
	if(c != 'D') {
		cout << "Unrecognized input. Char 'D' expected.";
		return 1;
	}
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;
	int *a = new int[n];
	for(int j = 0; j < n; j++) {
		a[j] = j+1;
	}
	long long int i;
	cin >> i;
	find_permutation(a, 0, i, n, n);
}

void find_permutation(int a[], int left, long long int i, int length, int clen) {
	if(clen == 1) {
		for(int j = 0; j < length; j++) {
			cout << a[j] << " ";
		}
	}else
	{
		int num = recv(clen-1);
		int cc = (i-1) / num;//choose a[cc] as the next number in ith permutation
		if(i % num == 0) {i = num;}
		else {i = i % num;}
		swap(a, left, left+cc);
		a = rearrange_array(a, left, cc+left, length);
		find_permutation(a, left+1, i, length, clen-1);
	}
}


//factorial of n
long long int recv(int n) {
    long long int sum = 1;
    if(1 == n)
    {
        return 1;
    }
    sum =n * recv(n - 1);
}

void swap(int *a, int num1, int num2) {
	int tmp = a[num1];
	a[num1] = a[num2];
	a[num2] = tmp;
}

int* rearrange_array(int a[], int left, int i, int n) { // rearrange array to make it in an increasingo order from index left+1 to the end
	int *temp = new int[n];
	for (int j = 0; j < n;j++)
	{
		temp[j] = a[j];
	}
	if(left == i || i-left == 1){
		return temp;
	}else{
		temp[left + 1] = a[i];
		for(int j = left + 2; j <= i; j++){
			temp[j] = a[j - 1];
		}
		return temp;
	}
	
}
