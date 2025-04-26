#include <iostream>
#include <thread>
#include <mutex>

typedef long long ll;
ll total = 0;
std::mutex mtx; // Our lock

void calculateSum(ll n) {
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        sum += i;
    }
    // Lock before modifying shared resource
    mtx.lock();
    total += n;
    mtx.unlock(); // Unlock once done
}

int main() {
    ll n = 1000000000;
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    
    std::thread t1(calculateSum, n); 
    std::thread t2(calculateSum, n + 1);
    t1.join(); 
    t2.join();
    
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Total: " << total << std::endl; // Expected total: 2000000001
    std::cout << "Time taken with mutex: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}