//Write your code here
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

string upper(string );

int main(){
    vector<string> name;
    vector<string> grade;
    int num1,num2,num3,Gnum;
    string G;
    char Na[100];
    ifstream n("name_score.txt");
    string N;
    while(getline(n,N)){
        sscanf(N.c_str(),"%[^:]:%d %d %d",Na,&num1,&num2,&num3);
        name.push_back(Na);
        Gnum = 0;
        Gnum = num1+num2+num3;
        if(Gnum >= 80) G = "A";
        else if(Gnum >=70 && Gnum <= 79) G = "B";
        else if(Gnum >=60 && Gnum <= 69) G = "C";
        else if(Gnum >=50 && Gnum <= 59) G = "D";
        else if(Gnum < 50 ) G = "F";
        grade.push_back(G);
        
    }
    while(1){
        string word;
        cout << "Please input your command :";
        getline(cin,word);
        int idx = word.find_first_of(" ");
        string s1 = upper(word.substr(0,idx));
        string s2 = upper(word.substr(idx+1,word.size()));
        if(s1 == "NAME"){
            cout << "---------------------------------" << "\n";
            int n=0;
            for(int i=0;i<name.size();i++){
                
                if(s2 == upper(name[i])){
                    cout << name[i] << "'s grade = " << grade[i] << "\n";
                    n++;
                }
            }
            if(n == 0) cout << "Cannot found." << "\n" ;
            cout << "---------------------------------" << "\n";
        }else if(s1 == "GRADE"){
            cout << "---------------------------------" << "\n";
            for(int i=0;i<grade.size();i++){
                if(s2 == upper(grade[i])) cout << name[i] << "\n";
            }
            cout << "---------------------------------" << "\n";
        }else if(s1 == "EXIT"){
            break;
        }else{ cout << "Invalid command" << "\n";}
    }
    
    

    
}

string upper(string x){
    int i = 0;
    while(x[i]){
        x[i] = toupper(x[i]);
        i++;
    }
    return x;
}