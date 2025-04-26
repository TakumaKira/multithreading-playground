#include <iostream>
#include <thread>

typedef long long ll;

void calculateSum(ll n) {
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        sum += i;
    }
}

int main() {
    ll n = 1000000000;
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); // start time
    std::thread t1(calculateSum, (ll)n); 
    std::thread t2(calculateSum, (ll)n);
    t1.join(); 
    t2.join();
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); // end time
    std::chrono::duration<double> elapsed = end - start; // time taken to call func twice
    std::cout << "Time taken while using additional thread: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}