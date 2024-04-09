#include <bits/stdc++.h>
#define N 1000000
#define ll long long
using namespace std;
#define N 100000
void primeSieve(vector<int> &sieve){
    sieve[1]=sieve[0]=0;
    
    //Initially you can say I will just mark all odd numbers as prime    
    for(int i=3;i<=N;i+=2){
        sieve[i]=1;
    }
    
    for(ll i=3;i<=N;i++){
        if(sieve[i]){
            for(ll j=i*i;j<=N;j=j+i){
                sieve[j]=0;
            }
        }
    }
    
}

//Optimisised Approach
// Obs: Once N is reduced to a prime number, the 
// only factor that number will be the number itself

// if a number does't have nay factor till sqrt(n)
// then it ia a prime number
// O(sqrt(N))
void factorise(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
    //Out of the loop
    if(n!=1){
        cout<<n<<"^"<<1;
    }
}


int sieveArr[N+1]={0};
vector<int> primes;

void sieve(){
    for(long long i=2;i<=N;i++){
        if(sieveArr[i]==0){
            primes.push_back(i);
            for(long long j=i*i;j<=N;j+=i){
                sieveArr[j]=1;
            }
        }
    }    
}



int main() {
    // Write C++ code here
    // vector<int> sieve(N,0);
    // primeSieve(sieve);
    // for(int i=0;i<=1000;i++){
    //     if(sieve[i]){
    //         cout<<i<<" ";
    //     }
    // }
    
    // int n;
    // cin>>n;
    // factorise(n);
    // return 0;
    
    
    //segmented sieve
    sieve();
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> segment(n-m+1,0);
        
        for(auto p: primes){
            //stop when p^2 > n
            if(p*p>n){
                break;
            }
            
            //otherwise we need to find the nearest starting point
            int start= (m/p)*p;
            
            if(p>=m and p<=n){
                start=2*p;
            }
            
            //start making the number as not prime from start
            for(int j=start;j<=n;j=j+p){
                if(j<m){
                    continue;
                }
                segment[j-m]=1;
            }
        }
        
        //pimes stored as 0 in the segment
        
        for(int i=m;i<=n;i++){
            if(segment[i-m]==0 and i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}
