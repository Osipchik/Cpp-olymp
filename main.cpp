#include <iostream>
#include <vector>

using namespace std;

bool check(string str, vector<string> vec);

int main()
{
    int X1 = 1, Y1 = 1, X2 = 2, Y2 = 3;
    int Px = 1, Py = 2, Pr = 1;

    vector<string> OXY;
    vector<string> Oxy;

    for(int x = X1; x <= X2; x++)
    {
        for(int y = Y1; y <= Y2; y++)
        {
            OXY.push_back(to_string(x) + to_string(y));
        }
    }


    string item;
    for(int x = Px, count = 0, tx = 0; x + tx <= Px + Pr; tx++)
    {
        for(int y = Py, ty = 0; y + ty <= Py + Pr - count; ty++)
        {
            item = to_string(x + tx) + to_string(y + ty);
            if(!check(item, Oxy)) Oxy.push_back(item);
            item = to_string(x + tx) + to_string(y - ty);
            if(!check(item, Oxy)) Oxy.push_back(item);
            item = to_string(x - tx) + to_string(y + ty);
            if(!check(item, Oxy)) Oxy.push_back(item);
            item = to_string(x - tx) + to_string(y - ty);
            if(!check(item, Oxy)) Oxy.push_back(item);
        }
        count++;
    }

    int count = 0;
    for(int i = 0; i < Oxy.size(); i++)
        if(check(Oxy[i], OXY)) count++;
    cout << OXY.size() - count;

    return 0;
}

bool check(string str, vector<string> vec)
{
    int total = vec.size();
    for(int i = 0; i < total; i++)
    {
        if(str == vec[i]) return true;
    }
    return false;
}
