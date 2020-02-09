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
        elems[i] = reverse[i] = i;
        marks[i] = -1;
    }

    marks[0] = 0;
    elems[0] = elems[N + 1] = N + 1;
    counter = N;
    while (counter != 1)
    {
        //copy(elems.begin(), elems.end(), ostream_iterator<int>(cout, " "));
        counter = N;
        while (elems[reverse[counter] + marks[counter]] > counter && counter > 1)
        {
            marks[counter] = -marks[counter];
            counter--;
        }
        int tmp = elems[reverse[counter] + marks[counter]];
        elems[reverse[counter] + marks[counter]] = elems[reverse[counter]];
        elems[reverse[counter]] = tmp;
        tmp = reverse[elems[reverse[counter]]];
        reverse[elems[reverse[counter]]] = reverse[counter];
        reverse[counter] = tmp;
    }
    double duration = t.elapsed();
    cout << duration << endl;
    return 0;
}

