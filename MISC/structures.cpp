#include<iostream>
using namespace std;


typedef struct emplyee{
  //data
  int ID;
  string name;

} ep;

union money{
  //data
  int rice;
  char car;

};

int main(){
  // union money currency;
  // currency.rice=69;
  // cout<<currency.rice<<endl;

  // currency.car='g';
  // cout<<currency.rice<<endl;//garbage value
  // cout<<currency.car<<endl;

  enum meal{lunch,dinner,breafast};
  meal m= lunch;
  cout<<m;



  // ep niga;
  // niga.ID=69;
  // niga.name="Nega";
  // cout<<niga.name<<" "<<niga.ID<<endl;
  return 0;
}