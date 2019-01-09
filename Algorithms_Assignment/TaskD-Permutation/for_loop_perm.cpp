//#include<iostream>
//#include<vector>
//using namespace std;
//long long factorial(int n){
//    long long output = 1;
//    if(n==0){
//        return 1;
//    }
//    while(n!=1){
//        output*=n;
//        n--;
//    }
//    return output;
//}
//int main(){
//    //char question_type;
//    //cin >> question_type;
//    int n;
//    cin >> n;
//    vector<int> Ordered_array;
//    for(int count = 0; count < n; count++){
//        int x;
//        cin >> x;
//        Ordered_array.push_back(x);
//    }
//    long long factoria = factorial(n);
//    long long count = 0;
//    while(count < factoria/n){
//        for(int count2 = 0; count2 < (factoria/n)-1; count2++){
//            cout << Ordered_array[count];
//        }
//        count++;
//    }
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array;
    
    for(int count = 1; count <= n; count++){
        array.push_back(count);
    }
    do {
        for(int i=0; i<array.size(); ++i) {
            cout << array[i] << (i+1!=n?" ":"\n");
        }
    } while (next_permutation(array.begin(), array.end()));
    return 0;
}

