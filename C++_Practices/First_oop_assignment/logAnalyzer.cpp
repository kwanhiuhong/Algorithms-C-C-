//
//  main.cpp
//  Assignment2
//
//  Created by KHH on 29/10/2018.
//  Copyright © 2018年 關曉康. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>
#include <string>
using namespace std;
//Page defintion
class Page{
public:
    int id;
    string path;
    int counter;
    Page(int page_id, string page_path){
        id = page_id;
        path = page_path;
        counter = 0;
    };
    friend bool operator<(const Page &a, const Page &b);
};
bool operator<(const Page &a, const Page &b){
    if(a.counter == b.counter){
        return (a.path < b.path);
    }
    return !(a.counter < b.counter);
}

//user class definition
class User{
public:
    int id;
    vector<string> visits;
    User(int user_id){
        id = user_id;
    };
    void add_visit(string page_path){
        visits.push_back(page_path);
    };
    int size() const{
        return int(visits.size());
    };
    void print_visits(){
        vector<string>::iterator itr;
        for(itr = visits.begin(); itr != visits.end(); itr++){
            cout << "- " << *itr << endl;
        }
    };
    friend bool operator<(const User &a, const User &b);
};
bool operator<(const User &a, const User &b){
    if(a.size() == b.size()){
        return a.id < b.id;
    }
    return !(a.size() < b.size());
}
bool compare0(const Page &a, const Page &b){
    return a.id < b.id;
}
bool compare1(const Page &a, const Page &b){
    return (a.id < b.id);
}
bool compare2(const string a, const string b){
    return a < b;
}
int main(){
    //ifstream input;
//    string file_name;
//    cin >> file_name;
    //input.open(file_name);
    vector<Page> pages;
    vector<User> users;
    string a_word;
    
    int count_user_index = -1;
    int avoid_duplicate_sort = 0;
    while(cin >> a_word){
        if(a_word == "PAGE"){
            int page_id;
            string page_path;
            cin >> page_id;
            cin >> page_path;
            Page a_page(page_id, page_path);
            pages.push_back(a_page);
        }else if(a_word == "USER"){
            if(avoid_duplicate_sort == 0){
                sort(pages.begin(), pages.end(), compare0);
                avoid_duplicate_sort++;
            }
            int user_id;
            cin >> user_id;
            User a_user(user_id);
            users.push_back(a_user);
            count_user_index++;
        }else if(a_word == "VISIT"){
            int page_id;
            cin >> page_id;
            vector<Page>::iterator itr;
            Page temp(page_id, "N/A");
            itr = lower_bound(pages.begin(), pages.end(), temp, compare1);
            ((*itr).counter)++;
            users[count_user_index].add_visit((*itr).path);
        }
    }
    
    cout << "*** 5 most popular pages ***\n";
    sort(pages.begin(), pages.end());
    for(int cnt = 0; cnt < 5; cnt++){
        cout << pages[cnt].counter << ':' << pages[cnt].path << endl;
    }
    cout << "*** 5 most active users ***\n";
    sort(users.begin(), users.end());
    for(int cnt = 0; cnt < 5; cnt++){
        cout << users[cnt].size() << ':' << users[cnt].id << endl;
        sort(users[cnt].visits.begin(), users[cnt].visits.end(), compare2);
        users[cnt].print_visits();
    }
    return 0;
}
