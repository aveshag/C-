#include <iostream>

using namespace std;

class MathObject
{
    mutable bool piCached;
    mutable double pi_;

public:
    MathObject() : piCached(false)
    {
    }
    double pi() const
    {
        if (!piCached)
        {
            pi_ = 4;
            for (long step = 3; step < 1000000000; step += 4)
            {
                pi_ += ((-4.0 / (double)step) + (4.0 / ((double)step + 2)));
            }
            piCached = true;
        }
        return pi_;
    }
    
};

int main()
{
    const MathObject mo;
    cout << mo.pi() << endl;
}