#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int AdderFunction(int a, int b)
{ // A function
    return a + b;
}

class AdderFunctor
{
public:
    int operator()(int a, int b)
    { // A functor
        return a + b;
    }
};

// The value returned indicates whether the element
// passed as first argument is considered to go before the second in the specific strict weak
// ordering it defines.
bool compare(const int &a, const int &b)
{
    if (a > b)
        return true;
    return false;
}

int main()
{
    int x = 5;
    int y = 7;
    int z = AdderFunction(x, y); // Function invocation
    AdderFunctor aF;             // Here, Construtor is called
    int w = aF(x, y);            // aF.operator()(x, y); -- Functor invocation

    vector<int> v = {1, 3, 6, 2, 4};
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
