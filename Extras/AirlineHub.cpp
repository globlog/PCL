// C++ program to calculate Distance
// Between Two Points on Earth
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Utility function for
// converting degrees to radians
long double toRadians(const long double degree)
{
	// cmath library in C++
	// defines the constant
	// M_PI as the value of
	// pi accurate to 1e-30
	long double one_deg = (M_PI) / 180;
	return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
					long double lat2, long double long2)
{
	// Convert the latitudes
	// and longitudes
	// from degree to radians.
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);
	
	// Haversine Formula
	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
						cos(lat1) * cos(lat2) *
						pow(sin(dlong / 2), 2);

	return ans;
}

// Driver Code
int main()
{
    std::cout << std::setprecision(2) << std::fixed;
    int n;
    while (std::cin >> n){
        long double lat1,long1,lat2,long2, maxdistance,dist;
        std::vector<pair<long double,long double>> airports(n);
        for(int i = 0;i<n;++i){
            std::cin >> lat1 >> long1;
            airports[i]={lat1,long1};
        }
        std::vector<long double> hubdistance(n);
        for (int i = 0;i<n;++i){
            lat1 = std::get<0>(airports[i]);
            long1 = std::get<1>(airports[i]);
            maxdistance = 0.0;
            for (int j = 0;j<n;++j){
                lat2 = std::get<0>(airports[j]);
                long2 = std::get<1>(airports[j]);
                dist = distance(lat1, long1, lat2, long2);
                if (dist>maxdistance){
                    maxdistance = dist;
                }
            }
            hubdistance[i]=maxdistance;
        }
        int minElementIndex = 0;
        long double minimum = hubdistance[0];
        for (int i = 0;i<n;++i){
            if (hubdistance[i] <= minimum){
                minElementIndex = i;
                minimum = hubdistance[i];
            }
        } 

        //int minElementIndex = std::min_element(hubdistance.rbegin(),hubdistance.rend()) - hubdistance.rbegin();
        std::cout << std::get<0>(airports[minElementIndex]) << " " << std::get<1>(airports[minElementIndex]) << std::endl;
    }
	return 0;
}

// This code is contributed
// by Aayush Chaturvedi

