#include <iostream>
using namespace std;

int find_largest(int p[400]);

int main(){
    int tests;
    cin >> tests;
    for(int count = 0; count < tests; count++){
        int tables;
        cin >> tables;
        int p[400];
        for(int cnt1 = 0; cnt1 < 400; cnt1++) {
            p[cnt1] = 0;
        }
        
        for(int count = 0; count < tables; count++){
            int a,b;
            cin >> a >> b;
            if(a < b){
                for(int count = a-1; count < b; count++){
                    p[count]++;
                }
            }
            if(a > b){
                for(int count = b-1; count < a; count++){
                    p[count]++;
                }
            }
            if(a < b){
                if(a%2 == 0 && b%2 != 0){
                    p[b]++;
                    p[a-2]++;
                }
                if(a%2 == 0 && b%2 == 0){
                    p[a-2]++;
                }
                if(a%2 != 0 && b%2 != 0){
                    p[b]++;
                }
            }
            if(b < a){
                if(b%2 == 0 && a%2 != 0){
                    p[a]++;
                    p[b-2]++;
                }
                if(b%2 == 0 && a%2 == 0){
                    p[b-2]++;
                }
                if(b%2 != 0 && a%2 != 0){
                    p[a]++;
                }
            }
        }
        cout << find_largest(p)*10 << endl;
        
    }
    return 0;
}

int find_largest(int p[400]){
    int largest = 0;

    largest = p[0];
    for(int count = 1; count < 400; count++){
        if(p[count] > largest){
            largest = p[count];
        }
    }
    return largest;
}
