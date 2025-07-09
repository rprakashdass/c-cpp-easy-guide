#include <iostream>
using namespace std;

class SampleTest{
    private:
        string nickName;
    
    public:
        void setName(string name){
            nickName = "cuttie " + name;
        }
        string getName(){
            return nickName;
        }
};

int main()
{
    SampleTest obj;
    string name;
    cout << "Enter your good name please!!!" << endl;
    cin >> name;
    obj.setName(name);
    cout << "Your Sweet Name with a generated nickname is " << "\"" << obj.getName() << "\"" << endl;
    return 0;
}