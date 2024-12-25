#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int number,choice;
int main() 
{  cout<<"Guess the number from 1..100"<<endl;
   srand (time (NULL));
   number = rand()%100+1;
   cin>>choice;
   cout<<choice<<endl;
   
  //The loop ""while"" performs on PC. 
  //while(number!=choice) 
  //{
  if (choice==number)
  {
      cout<<"Congratulations!..You win "<<endl;
  }
 if (choice>number)
  {
     cout<<"Too big number "<<endl;
  }
 else if(choice<number)
  {
    cout<<"Too small number "<<endl; 
  }
// } 
  cout<<endl<<"Correct number is "<<number<<endl;

    return 0;
}
