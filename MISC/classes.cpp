#include <iostream>
#include <string>
using namespace std;

class player
{

public:
    string name, gun;
    int age;
    void printName();
    void enterStats();
    void stats();

private:
    int rank;
};

void player ::printName()
{
    cout << name << endl;
}
void player ::enterStats()
{
    cout << "Enter name, age, gun and rank" << endl;
    cin >> name >> age >> gun >> rank;
}
void player ::stats()
{
    cout << name << endl;
    cout << gun << endl;
    cout << age << endl;
    cout << rank << endl;
}

int main()
{
    cout << "Welcome to the Game" << endl;
    player nigga;

    nigga.enterStats();
    nigga.age = 18;
    nigga.name = "Gae";
    nigga.stats();
    return 0;
}