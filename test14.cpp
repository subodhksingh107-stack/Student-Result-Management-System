#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

class student {
public:
string name;
int roll;
int marks[3];
int total=0;
float percentage;

student (string n, int r){
  this ->name = n;
  this ->roll = r;
 
}

void addmarks (){
  cout << "Enter marks of student in English, Hindi and Maths\n";
      for (int i = 0; i < 3; i++)
      {
       cin >> marks[i];
      }
}

void result (){
for (int i = 0; i < 3; i++)
{
 total += marks[i];
} 
percentage = (total*100) / 300;
cout << "The total marks of roll number = " << roll << " is " << total << " and percentage = " << percentage << endl;

}



};

int main (){
  vector <student> s1;
  string name;
int roll;
int marks[3];
  int x;
  while (true){
    cout << "--------WELCOME TO STUDENT DATA--------\n";
    cout << "1. Add student\n" << "2. Add marks of 3 subjects \n" << "3. Calculate Result\n" << "4. Display all students\n" << " 5. Search student \n" << " 6. Show Topper \n" << "7. Exit \n";
    cin >> x;
    if (x == 1){
      cout << "Enter name of student \n";
      cin.ignore();
      getline (cin, name);
      cout << "Enter Roll number of student \n";
      cin >> roll;
   
      s1.push_back(student(name, roll));
    } else if (x == 4 || x == 5 || x == 6){


      switch (x)
      {
      case 4:
        cout << "The students are : \n";
        for (int i = 0; i < s1.size(); i++)
        {
          cout << s1[i].name << endl;
        }
        break;

        case 5 :
         int y;
        cout << "Enter roll number to search \n";
        cin >> y;
        for (int i = 0; i < s1.size(); i++)
        {
         if (s1[i].roll == y){
            cout << "The name of student is " << s1[i].name << endl;
         }
        
        }
        
        break;

      case 6: {
    if (s1.empty()) {
        cout << "No students available.\n";
        break;
    }
    auto topper = max_element(s1.begin(), s1.end(),
        [](const student &a, const student &b) {
            return a.percentage < b.percentage;
        });
    cout << "The topper of class is " << topper->name
         << " (Roll: " << topper->roll << ") with percentage = "
         << topper->percentage << endl;
    break;
}
     
      
      
      default:
        cout << "Incorrect option \n";
        break;
      }

    }  else   if (x == 2 || x == 3){
     int z;
      cout << "Enter roll number of student \n";
      cin >> z;
      for (int i=0; i<s1.size(); i++){

      if (s1[i].roll == z)
      {
      
      
      switch (x)
      {
      case 2 :
        s1[i].addmarks();
        break;
      
        case 3 :
        s1[i].result();
        break;

       

      default:
      cout << "Incorrect option \n";
        break;
      }
    }
    }
    } else  if (x == 7) {
      cout << "Thanks for visiting \n";
      break;
    }
  }
return 0;
}