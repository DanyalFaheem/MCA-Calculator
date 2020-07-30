/* 	Modified Class Average Calculator 
	To use it, create a vector of type int as Grand Totals are rounded off and then pass that vector to the MCA_calculator functions
	Include the vector with all the values, it can be sorted or unsorted/
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void display(vector <int> v1) {
        cout <<  "Vector :";
    for(int counter = 0; counter < v1.size(); counter++) {
        cout << " " << v1[counter];
    }
    cout << endl;
}

double standard_deviation(vector <int> data, int n)
{
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<n;++i)
    {
        mean+=data[i];
    }
    mean=mean/n;
    for(i=0; i<n;++i)
    sum_deviation+=(data[i]-mean)*(data[i]-mean);
    return sqrt(sum_deviation/n);          
}

void MCA_calculator(vector <int> v) {
    int sum = 0;
    srand(time(0));
    for(int counter = 0; counter < v.size(); counter++) {
        //v.push_back(rand() % 56 + 28);
        sum += v[counter];
    }
    sort(v.begin(), v.end());
    vector <int> v2, v3;
    for(int counter = 0 ; counter < v.size() / 2; counter++) {
        v2.push_back(v[counter]);
    }
    for(int counter = v.size() / 2; counter < v.size(); counter++) {
        v3.push_back(v[counter]);
    }
    int sum2 = 0, count = 0;
    double median = (v[v.size() / 2] + v[(v.size() - 1) / 2]) / 2;
    double q1 = ((v2[v.size() / 4] / 2) + (v2[(v.size() - 1) / 4] / 2)) / 2;
    double q3 = ((v3[v.size() / 4] / 2) + (v3[(v.size() - 1) / 4] / 2)) / 2;
    for(int counter = 0; counter < v.size(); counter++) {
        if(v[counter] > (median + ((q3 - q1) * 1.5)) or v[counter] < (median - ((q3 - q1) * 1.5))) {
        }
        else {
            sum2 += v[counter];
            count++;
        }
    }
    display(v);
    cout << "Average: " << sum / v.size() << endl << "Median: " << median << endl << "Q1: " << q1 << endl << "Q3: " << q3 << endl << "Std Dev: " << standard_deviation(v, v.size()) << endl << "MCA: " << sum2 / count << endl << "Total values after removing outliers: " << count << endl;
}

int main()
{
    vector <int> v;
    srand(time(0));
    for(int counter = 0; counter < 150; counter++) {
        v.push_back(rand() % 37 + 38); // Currently using random values between 28 and 82(56+28=82)
    }
    MCA_calculator(v);
    return 0;
}

