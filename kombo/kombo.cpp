#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

int main()
{
    vector <size_t> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    boost::timer t;
    t.restart();
    sort(v.begin(), v.end());
    do
    {
       
    } while (next_permutation(v.begin(), v.end()));
    double duration = t.elapsed();
    cout << duration << endl;
    return 0;
}

