#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<string> Universe;

// iterative approach
void powerSet_it ()
{
    int set_size = n;

    int power_set_size = pow(2,set_size);

    for(int i=0 ; i<power_set_size ; i++)
    {
        for(int j=0 ; j<set_size ; j++)
        {
            if(i & (1 << j))                    // if the bit is set
                cout << Universe[j] << " ";
        }
        cout << endl;
    }
}

// recursive approach
vector<string> PossibleSet;

void GenerateSets(int index=0){
    if(index == n){
        for(int i=0;i<PossibleSet.size();i++){
            cout << PossibleSet[i] << " ";
        }
        cout << endl;
        return;
    }

    PossibleSet.push_back(Universe[index]);
    GenerateSets(index +1);
    PossibleSet.pop_back();
    GenerateSets(index+ 1);
}

int main()
{
    cout << "Enter the number of elements of the set" << endl;
    cin >> n;
    cout << "Enter elements of the set" << endl;
    string element;
    for(int i=0;i<n;i++){
        cin >> element;
        Universe.push_back(element);
    }
    short x;
    cout << "Enter 1 for iterative approach & 2 for recursive approach:" << endl;
    cin >> x;
    cout << "The subsets are:" << endl;
    switch(x)
    {
        case 1:
            powerSet_it();
            break;
        case 2:
            cout << endl;
            GenerateSets();
            break;
    }
    return 0;
}
