#include <iostream>
#include <string>

using namespace std;

int main(){
    
    class Haab{
    public:
        int day;
        char stop;
        string months;
        int conversion(string months){
            string name[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
            for (int count = 0; ;count++){
                if (name[count] == months){
                    return count+1;
                    break;
                }
            }
        }
        int year;
    };
    
    class Tzolkin{
    public:
        int numbers;
        int days;
        string jjjj;
      
        void convert(int days){
            string name1[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
                "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
            for (int count = 0; ;count++){
                if (count == days){
                    jjjj = name1[count-1];
                    break;
                }
            }
        }
        int year;
    };
    
    int no;
    cin >> no;
    cout << no << endl;
    Haab *aa;
    aa = new Haab[no];
    Tzolkin *bb;
    bb = new Tzolkin[no];
    
    for (int count = 0; count < no; count++){
        cin >> aa[count].day >> aa[count].stop >> aa[count].months >> aa[count].year;
        int day = 20 * (aa[count].conversion(aa[count].months) - 1);
        day += (aa[count].day + 1);
        day += aa[count].year * 365;
        if (day%13 == 0) bb[count].numbers = 13;
        else bb[count].numbers = day%13;
        if (day%20 == 0) {
            bb[count].days = 20;
            bb[count].convert(20);
        }  else {
            bb[count].days = day%20;
            bb[count].convert(day%20);
        }
        if (day%260 != 0){
            bb[count].year = day/260;
        }   else {
            bb[count].year = day/260 - 1;
        }
        cout << bb[count].numbers << " " << bb[count].jjjj << " " << bb[count].year << endl;
    }
    delete[] aa;
    delete[] bb;
    return 0;
}
