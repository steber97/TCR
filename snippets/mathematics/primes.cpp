#include "../header.h"
#include "numbertheory.cpp"
constexpr ll SIZE = 1e6+10;
bitset<SIZE + 1> bs;
vector<ll> primes;

void sieve() { // call at start in main!
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= SIZE; i++) if (bs[i]) {
		for (ll j = i * i; j <= SIZE; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}

bool is_prime(ll n) { // for N <= SIZE^2
	if (n <= SIZE) return bs[n];
	for(const auto &prime : primes)
	   	if (n % prime == 0) return false;
	return true;
}

struct Factor{ll prime; ll exp;};
vector<Factor> factor(ll n) {
	vector<Factor> factors;
	for(const auto &prime : primes){
		if(n==1 || prime*prime > n) break;
		ll exp=0;
		while(n % prime == 0)
		   	n/=prime, exp++;
		if(exp>0)
			factors.push_back({prime,exp});
	}
	if (n != 1) factors.push_back({n,1});
	return factors;
}

vector<ll> divisors(ll n){
	auto fs = factor(n); vector<ll> ds{1};
	ds.reserve(accumulate(fs.begin(),fs.end(),0,
		[](ll a,ll e){return a*(e+1);}));
	for(auto f : fs) for(auto d : ds) for(ll i = 0; i <= f.exp; ++i)
				ds.push_back(d), d*=f.prime;
	return ds;
}

vector<ll> mf(SIZE + 1, -1);		// mf[i]==i when prime
void sieve2() { // call at start in main!
	mf[0] = mf[1] = 1;
	for (ll i = 2; i <= SIZE; i++) if (mf[i] < 0) {
		mf[i] = i;
		for (ll j = i * i; j <= SIZE; j += i)
			if(mf[j] < 0) mf[j] = i;
		primes.push_back(i);
	}
}

vector<Factor> factor2(ll n){
	vector<Factor> factors;
	while(n>1){
		if(factors.back().prime == mf[n]) factors.back().exp++;
		else factors.push_back({mf[n],1});
		n/=mf[n];
	}
	return factors;
}

ll num_div(ll n) {
	ll divisors = 1;
	for(auto &&p : factor(n))
		divisors *= p.exp + 1;
	return divisors;
}

ll bin_pow(ll b, ll e){
	ll p = e==0 ? 1 : pow(b*b,e>>1);
	return p * p * (e&1 ? b : 1);
}

ll sum_div(ll n) {
	ll sum = 1;
	for(const auto &p : factor(n))
		sum *= (pow(p.prime, p.exp+1) - 1) / (p.prime - 1);
	return sum;
}

ll phi(ll n) {
	ll ans = n;
	for(const auto &p : factor(n))
		ans -= ans / p.prime;
	return ans;
}

vector<ll> test_primes = {2,3,5,7,11,13,17,19,23}; // sufficient to 3.8e18
bool miller_rabin(const ll n){ // true when prime
	if(n<2) return false;
	if(n%2==0) return n==2;
	ll s = 0, d = n-1; // n-1 = 2^s * d
	while(~d&1) s++, d/=2;
	for(auto a : test_primes){
		if(a > n-2) break;
		ll x = powmod(a,d,n);	// needs powmod with mulmod!
		if(x == 1 || x == n-1) continue;
		REP(i,s-1){
			x = mulmod(x,x,n);
			if(x==1) return false;
			if(x==n-1) goto next_it;
		}
		return false;
next_it:;
	}
	return true;
}
