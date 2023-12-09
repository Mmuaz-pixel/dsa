#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std; 

int main()
{
    chrono::high_resolution_clock::time_point start, end;
    start = chrono::high_resolution_clock::now();

    long int n = 100000000;
    long int j, k;
    for (long int i = 0; i < n; i++)
    {
        j = i;
        k = i;
    }
    
    end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = chrono::duration_cast<chrono::duration<double>>(end - start);
    double seconds = duration.count();

    cout << "Total time taken was: " << fixed << setprecision(5)
              << seconds << " s" << endl;

    return 0;
}
