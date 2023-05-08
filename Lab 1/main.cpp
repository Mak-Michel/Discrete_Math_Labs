#include <bits/stdc++.h>

using namespace std;

int getBit(int number, int position)
{
    int bit = (number >> position)&1;
    return bit;
}

int setBit(int number, int position)
{
    number |= (1 << position);
    return number;
}

int clearBit(int number, int position)
{
    number &= ~(1 << position);
    return number;
}

int updateBit(int number, int position, int value)
{
    if(value)
        return setBit(number , position);
    else
        return clearBit(number , position);
}

int number_of_1s(unsigned int number)
{
    int counter=0;
    while(number)
    {
        if(number & 1)
            counter++;
        number >>= 1;
    }
    return counter;
}

int main()
{
    cout << "For part 1 press: 1 \nFor part 2 press: 2 \nFor part 3 press: 3"<<endl;
    short part;
    cin >> part;
    switch(part)
    {
        // part 1
        case 1:
            while(1){
                cout << "For getBit    press: 1 \nFor setBit    press: 2 \nFor clearBit  press: 3 \nFor updateBit press: 4\nTo exit       press: 5" << endl;

                int ans;

                short function_choice;
                cin >> function_choice;

                if(function_choice == 5)
                    return 0;

                int number;
                int position;
                cout << "Enter number:";
                cin >> number;
                cout << "Enter position:";
                cin >> position;

                switch (function_choice)
                {
                    case 1:
                        ans = getBit(number , position);
                        break;

                    case 2:
                        ans = setBit(number , position);
                        break;

                    case 3:
                        ans = clearBit(number, position);
                        break;

                    case 4:
                        int value;
                        cout << "Enter value:";
                        cin >> value;
                        ans = updateBit(number, position, value);
                        break;
                }

                cout << ans << endl;
            }

        // part 2
        case 2:
        {
            int nU;
            cout << "Enter the size of the Universal set" << endl;
            cin >> nU;
            vector<string> U (nU);
            map<string,int> m;
            cout << "Enter the elements of the Universal set"<< endl;
            for(int i=0;i<nU;i++)
            {
                cin >> U[i];
                m[U[i]] = i;
            }
            int n_sets;
            cout << "Enter the number of the subsets" << endl;
            cin >> n_sets;
            vector<vector<string>> sets (n_sets);
            int sets_id[n_sets] = {0};
            string element;
            for(int i=0;i<n_sets;i++)
            {
                int n;
                cout << "Enter the size of set " << i+1 << endl;
                cin >> n;
                int num = 0;
                cout << "Enter the elements of set " << i+1 << endl;
                for(int j=0;j<n;j++)
                {
                    cin >> element;
                    num = setBit(num,nU - 1 - m[element]);
                    sets[i].push_back(element);
                }
                sets_id[i] = num;
            }
            while(1)
            {
                int in,in1,in2;
                cout << "Enter 1 for Union\nEnter 2 for Intersection\nEnter 3 for Complement\nEnter 4 to exit" << endl;
                cin >> in;

                if(in ==1)
                {
                    cout << "Choose two sets by their order where the order of the Universal set is 0" << endl;
                    cin >> in1 >> in2;
                    if(in1 == 0 || in2 == 0)
                    {
                        for(int i=0;i<nU;i++)
                            cout << U[i] << " ";
                    }
                    else
                    {
                        int result = sets_id[in1-1] | sets_id[in2-1];
                        for(int i=0;i<nU;i++)
                        {
                            if(getBit(result,nU-1-i))
                                cout << U[i] << " ";
                        }
                    }
                    cout <<endl;
                }
                else if(in == 2)
                {
                    cout << "Choose two sets by their order where the order of the Universal set is 0" << endl;
                    cin >> in1 >> in2;
                    if(in1 == 0 || in2 == 0)
                    {
                        for(int i=0;i<sets[max(in1,in2)-1].size();i++)
                            cout << sets[max(in1,in2)-1][i] << " ";
                    }
                    else
                    {
                        int result = sets_id[in1-1] & sets_id[in2-1];
                        for(int i=0;i<nU;i++)
                        {
                            if(getBit(result,nU-1-i))
                                cout << U[i] << " ";
                        }
                    }
                    cout <<endl;
                }

                else if(in == 3)
                {
                    cout << "Choose one set by its order where the order of the Universal set is 0" << endl;
                    cin >> in1;
                    if(in1 != 0)
                    {
                        int result = ~sets_id[in1-1];
                        for(int i=0;i<nU;i++)
                        {
                            if(getBit(result,nU-1-i))
                                cout << U[i] << " ";
                        }
                    }
                    cout <<endl;
                }
                else if(in == 4)
                    return 0;
            }
        }
        break;

        // part 3
        case 3:
            int input;
            while(1){
                cout << "For the single occurrence in an array press: 1\nFor the number of \"1\" bits in a number press: 2\nTo exit press: 3"<<endl;
                cin >> input;

                if(input == 1)
                {
                    cout << "Enter the size of the array" << endl;
                    int n;
                    cin >> n;
                    int nums[n];
                    cout << "Enter the elements of the array" << endl;
                    for(int i=0;i<n;i++)
                        cin >> nums[i];
                    int one_occurence = nums[0];
                    for(int i=1;i<n;i++)
                        one_occurence ^= nums[i];
                    cout << one_occurence << endl;
                }
                else if(input == 2)
                {
                    int num;
                    cout << "Enter the number" <<endl;
                    cin >> num;
                    cout << number_of_1s(num) << endl;
                }
                else
                    return 0;
            }
            break;
    }
    return 0;
}


