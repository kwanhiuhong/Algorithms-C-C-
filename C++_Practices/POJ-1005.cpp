#include<iostream>
#include<cmath>
using namespace std;
int main(){
	struct array{
		float x, y;
	};
	int N, Z;
	cin >> N;
	float pie = 3.141592654, r;
	array *dataset;
	dataset = new array[N];
	for (int cnt = 0; cnt < N; cnt++){
		cin >> dataset[cnt].x >> dataset[cnt].y;
		double sum = dataset[cnt].x*dataset[cnt].x + dataset[cnt].y*dataset[cnt].y;
		r = sqrt(sum);
		Z = (pie * (r*r)/2) / 50;
		cout << "Property " << cnt+1 << ": " << "This property will begin eroding in year " << Z+1 << ".\n"; 
	}
	cout << "END OF OUTPUT.";
	delete []dataset;
	return 0;
}
