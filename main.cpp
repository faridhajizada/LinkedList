#include <iostream>
#include <list>
using namespace std;


int main(){
    list<int> lst;
    lst.push_back(1);
    lst.push_front(2);
    lst.remove(1);

    for (list<int>::iterator it = lst.begin(); it != lst.cend(); it++){
        cout << *it << endl;
    }
    return 0;
}