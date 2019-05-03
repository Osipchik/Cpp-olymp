#include <iostream>

using namespace std;

int main()
{
    int num = 28, count4 = 0, count7 = 0;

    for(int i = 2, temp; i <= num/2 + 1; i++, count4 = 0, count7 = 0)
    {
        if(i == num/2 + 1) i = num;
        temp = i;
        if(num % temp == 0)
        {
            while(temp)
            {
                if(temp %10 == 4) count4++;
                else if(temp %10 == 7) count7++;
                temp /= 10;
            }
            if(temp == 0 && (count4 && count7)) cout << i << " yes" << endl;
            else if(count4 || count7) cout << i << " almost" << endl;
        }
    }


    return 0;
}
