#include <iostream>
#include <vector>

using namespace std;

void exEuclidean (int num1 , int num2)
{
    // 4 vectors for the remainder , quotient , first bezout coeff. , second bezout coeff
    vector <int> r;
    vector <int> q;
    vector <int> s;
    vector <int> t;
    // assigning the initials
    if(num1 >= num2)
    {
        r.push_back(num1);
        r.push_back(num2);
        s.push_back(1);
        s.push_back(0);
        t.push_back(0);
        t.push_back(1);
        q.push_back(0);
    }
    else if (num1 < num2)
    {
        r.push_back(num2);
        r.push_back(num1);
        t.push_back(1);
        t.push_back(0);
        s.push_back(0);
        s.push_back(1);
        q.push_back(0);
    }
    int j = 0;
    // our stopping condition is when the reminder = 0
    while(r.back() != 0)
    {
        q.push_back(r.at(j) / r.at(j+1));
        r.push_back(r.at(j) % r.at(j+1));

        // we start to assign new values to the coeff. vectors when we reach iteration number 2
        if(j > 1)
        {
            s.push_back(s.at(j-2) - q.at(j-1)*s.at(j-1));
            t.push_back(t.at(j-2) - q.at(j-1)*t.at(j-1));
        }

        cout << j << "   " << r.at(j) << "   " <<  r.at(j+1) << "   " << q.at(j+1) << "   " << r.at(j+2) << "   " << "   " <<  s.at(j) << "   " << t.at(j) << endl;
        j++;
        // assigning the last values "Bezout's coeff.s"
        if((r.at(j+1) == 0) && (j > 1))
        {
            s.push_back(s.at(j-2) - q.at(j-1)*s.at(j-1));
            t.push_back(t.at(j-2) - q.at(j-1)*t.at(j-1));
            cout << "\t\t\t" << s.at(j) << "   " << t.at(j) << endl;
        }
    }
    cout << "GCD is:" << r.at(j) <<endl;
    cout << "Bezout's coeffecients are:" << endl;
    // special case if the user insert a 0
    if(num2 == 0 || num1 == 0)
    {
        cout << "s:" << s.at(0) << endl;
        cout << "t:" << t.at(0) << endl;
    }
    else
    {
        cout << "s:" << s.back() << endl;
        cout << "t:" << t.back() << endl;
    }
}

int main()
{
    int num1 , num2;
    cout << "Enter the 2 numbers:" << endl;
    cin >> num1 >> num2;
    exEuclidean(num1,num2);
    return 0;
}
