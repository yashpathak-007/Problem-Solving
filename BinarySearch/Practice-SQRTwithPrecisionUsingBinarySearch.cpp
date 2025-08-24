#include <iostream>
using namespace std;
double binarySearchSQRT(int n)
{
    int st = 0;
    int end = n;
    double ans = -1;
    while (st <= end)
    {
        double mid = st + (end - st) / 2;
        double sq = mid * mid; // so that it can handle sq     values that exceeds the maximum value limit of int.

        if (sq == n)
        {
            return mid;
        }
        else if (sq < n)
        {
            ans = mid; // if not divided properly then stored round value will be return as the sq root stored in the ans variable in each iteration for sq less then  the number it dipicted the possible ans of the problem.
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

double sqrtPrecision(int n, int p, double tempSol) //finction to find the precision values for the square roots.
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < p; i++)
    {
        factor = factor / 10;
        // 0.1------i=1
        // 0.01-----i=2
        // 0.001----i=3
        for (double j = ans; j*j < n; j=j+factor)
        {
            ans = j;
        }
        
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number : " << endl;
    cin >> n;
    int p;
    cout << "Enter precision : " << endl;
    cin >> p;
    double tempSol = binarySearchSQRT(n);

    cout << "SQRT of " << n << " is : " << sqrtPrecision(n, p, tempSol);
}

//output:
// Enter number : 
// 37
// Enter precision : 
// 3
// SQRT of 37 is : 6.082
