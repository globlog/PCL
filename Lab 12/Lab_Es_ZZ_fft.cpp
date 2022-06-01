#include <bits/stdc++.h>
using namespace std;

// For storing complex values of nth roots
// of unity we use complex<long double>
typedef complex<long double> cd;

const long double PI  =3.14159265358979323846264338327950288419716939937510L;
// Recursive function of FFT
vector<cd> fft(vector<cd>& a){
	int n = a.size();

	// if input contains just one element
	if (n == 1)
		return vector<cd>(1, a[0]);

	// For storing n complex nth roots of unity
	vector<cd> w(n);
	for (int i = 0; i < n; i++) {
		long double alpha = -2 * PI * i / n;
		w[i] = cd(cosl(alpha), sinl(alpha));
	}

	vector<cd> A0(n / 2), A1(n / 2);
	for (int i = 0; i < n / 2; i++) {

		// even indexed coefficients
		A0[i] = a[i * 2];

		// odd indexed coefficients
		A1[i] = a[i * 2 + 1];
	}

	// Recursive call for even indexed coefficients
	vector<cd> y0 = fft(A0);

	// Recursive call for odd indexed coefficients
	vector<cd> y1 = fft(A1);

	// for storing values of y0, y1, y2, ..., yn-1.
	vector<cd> y(n);

	for (int k = 0; k < n / 2; k++) {
		y[k] = y0[k] + w[k] * y1[k];
		y[k + n / 2] = y0[k] - w[k] * y1[k];
	}
	return y;
}


vector<cd> invfft(vector<cd>& a)
{
	int n = a.size();

	// if input contains just one element
	if (n == 1)
		return vector<cd>(1, a[0]);

	// For storing n complex nth roots of unity	
	vector<cd> w(n);
	for (int i = 0; i < n; i++) {
		long double alpha = 2 * PI * i / n;
		w[i] = cd(cos(alpha), sin(alpha));
	}

	vector<cd> A0(n / 2), A1(n / 2);
	for (int i = 0; i < n / 2; i++) {

		// even indexed coefficients
		A0[i] = a[i * 2];

		// odd indexed coefficients
		A1[i] = a[i * 2 + 1];
	}

	// Recursive call for even indexed coefficients
	vector<cd> y0 = invfft(A0);

	// Recursive call for odd indexed coefficients
	vector<cd> y1 = invfft(A1);

	// for storing values of y0, y1, y2, ..., yn-1.
	vector<cd> y(n);

	for (int k = 0; k < n / 2; k++) {
		y[k] = y0[k] + w[k] * y1[k];
		y[k + n / 2] = y0[k] - w[k] * y1[k];
	}
	return y;
}

vector<cd> invfft_2(vector<cd>& a){
	vector<cd> y = invfft(a);
	int n = a.size();
	for (int k = 0; k < n; k++) {
		y[k] = y[k] / cd(n,0);
	}
	return y;
}




vector<cd> polymulti_fft(vector<cd> a){
    int n = 262144;
	vector<cd> c = fft(a);
    vector<cd> w(n);
    for (int i = 0; i < n; i++) {
        w[i] = c[i]*c[i];
    }
    return invfft_2(w);
}

// Driver code
int main()
{
	long long int norm = 50000;
	long long int n = 262144;
	long long int N;
	vector<cd> a(n);
	std::cin >> N;
	int x;
	long long int zeroes = 0;
	for (int i = 0 ; i<N;++i){
		std::cin >> x;
		if (x!=0){
			a[x+norm] += 1;
		} else {
			zeroes+=1;
		}
	}
	// set a[50000] = 0 as it must be zero;
	vector<cd> c = polymulti_fft(a);
	// set c[50000] = 0 as it must be absolutely zero;
	c[100000] = cd(0,0);
	long long int quanti = 0LL;
	// non zero
    for (int i = norm;i<=150000;++i){
		quanti += (long long int) std::round(std::round(c[i].real())*a[i-norm].real());
	}
	// a + a  = 2a accounted too many times, reduced
	for (int i = 25000;i<=75000;++i){
		quanti -= (long long int) std::round(a[i].real()*a[2*i-norm].real());
	}
	// a + (-a) = 0 a!=0
	for (int i = 0;i<norm;++i){
		quanti += (long long int) 2*std::round(a[i].real()*a[2*norm-i].real()*zeroes);
	}
	// a + 0 = a, a!=0
	for (int i = 0;i<=2*norm;++i){
		quanti += (long long int) 2*std::round(a[i].real()*(a[i].real()-1)*zeroes);
	}
	// 0 + 0 = 0
	quanti += zeroes*(zeroes-1)*(zeroes-2);

	std::cout << quanti << std::endl;
	return 0;
}

