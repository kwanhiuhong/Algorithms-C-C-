#include<iostream>
#include<string>
using namespace std;
int main(void){
	int length, line;
	cin >> length >> line;
	string *p;
	p = new string[line];
	int *inversion;
	inversion = new int[line];
	
	for (int count = 0; count < line; count++){
		cin >> p[count];
		int sort = 0;
		for (int cnt0 = 0; cnt0 < length; cnt0++){
			for (int cnt = cnt0+1; cnt < length; cnt++){
				if (p[count][cnt0] > p[count][cnt]){
					sort ++;
				}
			}
		}
		inversion[count] = sort;
	}
	int max = 0;
	for (int cnt = 1; cnt < length; cnt++){
		max += length - cnt;
	}
	for (int most_sorted = 0; most_sorted <= max; most_sorted++){
		for (int cnt = 0; cnt < line; cnt++){
			if (most_sorted == inversion[cnt]){
				cout << p[cnt] << "\n";
			}
		}
	}
	delete []p;
	delete []inversion;
	return 0;
}
