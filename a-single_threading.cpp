#include <iostream>
#include <chrono>

typedef long long ll;

void calculateSum(ll n) {
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        sum += i;
    }
}

int main() {
    ll n = 1000000000;
    // Everything executes in the main thread
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); // start time
    calculateSum(n);
    calculateSum(n);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); // end time
    std::chrono::duration<double> elapsed = end - start; // time taken to call func twice
    std::cout << "Time taken in main thread: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}