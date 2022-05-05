#include <list>

#include "MyList.h"

int main()
{
    MyList<int> l;

    // std::list<int> l;
    
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    cout << l.front() << endl;
    l.front() = 33;
    cout << l.front() << endl;
    cout << l.back() << endl;

        cout << l.size() << endl;
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    cout << l.front() << endl;
    cout << l.back() << endl;
    
    l.push_front(423);

    cout << l.front() << endl;
    
    MyList<int> sink;
    sink = l;
    cout << sink.front() << endl;
    cout << sink.back() << endl;
    
    return 0;
}

