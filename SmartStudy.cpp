/*Basic flashcard app for Portuguese beginners 
Author :Talent Yolanda Ndlovu
Date: 13/09/2024*/
#include <iostream>
#include <fstream>
#include <stdlib.h>// used for memory allocation
#include <cctype> //used to check individual characters
#include<cstdlib>
using namespace std;


class Subjects{
private:
string question;
string answer;
int id;

public: 

string add(string q, string a){
question=q;
answer=a;
id=rand()% 100;
string line;
line=question +"*"+answer;+"|"+to_string(id);  //adding the identifier number of the flashcard
return line;
}


void revise(string readline){
    string quest_view="";
    string correct_ans="";
    string user_answer="";
    bool same=1;
int ans_start;
cout<<"Question: ";
    for(int i=0;i<=readline.length();i++){ //this is the loop for outputting the question
        if (readline[i]!='*'){
 quest_view=quest_view+readline[i];
        }
        else{
            ans_start=i+1;
            break;
        }

    }
    cout<<quest_view<<endl;

for(int p=ans_start;p<=readline.length();p++){
correct_ans=correct_ans+readline[p];
}
cout<<"Enter your answer"<<endl;
getline(cin,user_answer);
for(int n=0;n<=user_answer.length();n++){
    
    if (user_answer[n]!=correct_ans[n]){
same=0; //had to do this because whenever i tried to do it directly the answers would result in a wrong answer even when right
break;
    }

}
if (same==1){
    cout<<"EUREKA, You've done it. Great job"<<endl;
}
else if(same==0){
   cout<<"Oh no, that is the wrong answer"<<endl;
    cout<<"The correct answer is : "<<correct_ans<<endl;
}
}
};


int main(){
    string q1,a1;
    int QuesNum;
    int id;
    string read;
    char user_response;
    string file_to_open;
    Subjects Science1;
    ofstream MyFile;
    ofstream MyFile2;

cout<<"Option 1: Questions are in Portuguese, enter the English translation"<<endl;
cout<<"Option 2:Questions are in English, enter the Portuguese translation"<<endl;
cout<<"Enter choice, 1 or 2"<<endl;

cin>>user_response;
if (user_response==1){
    file_to_open="Port_to_Eng";
   
}
else{
    file_to_open="Eng_to_Port";

}

MyFile.open("/Users/talentyolandandlovu/Documents/Cpp projects/"+file_to_open, ios::app);

cout<<"Would you like to add any flashcards? Y or N"<<endl;
cin>>user_response;
if(user_response=='Y'){
cout<<"Time to add more flashcards!!\n"; 
cout<<"How many flashcards would you like to add?"<<endl;
cin>>QuesNum;
system("clear");
getline(cin,q1);
    for(int i=1; i<=QuesNum;i++){
     cout<<"Input question\n"; 
     //in c++ as soon as a whitespace is encountered, our input is terminated therefore we must use getline
     getline(cin,q1);
     cout<<"Input answer"<<endl;
     getline(cin,a1);
     MyFile<<Science1.add(q1,a1)<<"\n";
     system("clear");
    }
}
MyFile.close();

cout<<"Would you like to revise your flashcards? Y or N";
cin>>user_response;
ifstream MyReadFile;
MyReadFile.open("/Users/talentyolandandlovu/Documents/Cpp projects/"+file_to_open);
if (user_response=='Y'){
    cout<<"REVISION TIME!!"<<endl;
    system("clear");
while(getline(MyReadFile,read)){;

Science1.revise(read);
}
}
else{
    cout<<"Until next time, byeeeee!";
}
MyReadFile.close();
}



