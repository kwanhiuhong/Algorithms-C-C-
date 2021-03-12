#include <iostream>
using namespace std;
int fast_fibo(int n){
    if(n == 0 | n == 1){
        return 0;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int cnt = 0; cnt < n; cnt ++){
        a = b;
        b = c;
        c = a+b;
    }
    return c;
}
int main(){
    int x;
    cin >> x;
    cout << fast_fibo(x) << endl;
    return 0;
}
