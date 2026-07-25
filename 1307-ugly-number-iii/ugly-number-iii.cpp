#define ii long long
class Solution {
public:
    int n, a, b, c;
    long long gcd(ii a, ii b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    ii lcm(ii x, ii y){
        return (x * 1LL * y)/gcd(x, y);
    }
    bool check(long long x){
        // tot number of values <= x >= n return 1
        ii tot = 0;
        ii ca = x/a;
        ii cb = x/b;
        ii cc = x/c;
        ii cab = x/lcm(a,b);
        ii cbc = x/lcm(b, c);
        ii cac = x/lcm(a, c);
        ii cabc = x/lcm(lcm(a,c), b);
        tot = ca + cb + cc - cab - cbc - cac + cabc;
        return tot >= n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        this -> n = n;
        this -> a = a;
        this -> b = b;
        this -> c = c;
        // let x be the nth number
        long long lo = 1, hi = 2e10;
        long long ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }  
        return ans;
    }
};