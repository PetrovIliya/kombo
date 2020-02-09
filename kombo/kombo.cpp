#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

#define N 10

int main()
{
    map <int, int> elems, reverse, marks;
    int counter;
    boost::timer t;
    t.restart();
    for (int i = 1; i <= N; i++)
    {
        elems[i] = i;
        reverse[i] = i;
        marks[i] = -1;
    }

    marks[0] = 0;
    elems[0] = elems[N + 1] = counter = N + 1;
    while (counter != 1)
    {
        copy(elems.begin(), elems.end(), ostream_iterator<size_t>(cout, " "));
        counter = N;
        while (elems[elems[counter] + marks[counter]] > counter)
        {
            -marks[counter];
            counter--;
        }
        int tmp = elems[elems[counter] + marks[counter]];
        elems[elems[counter] + marks[counter]] = elems[elems[counter]];
        elems[elems[counter]] = tmp;
    }
    double duration = t.elapsed();
    cout << duration << endl;
    return 0;
}

