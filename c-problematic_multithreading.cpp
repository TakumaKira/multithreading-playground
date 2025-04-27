#include <iostream>
#include <thread>

typedef long long ll;
ll total = 0;

void calculateSum(ll n) {
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        sum += i;
    }

    std::cout << "Reached Problematic Section for n: " << n << std::endl;
    // No lock here
    std::cout << "Current total: " << total << ", n: " << n << std::endl;

    ll temp = total;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add a small delay
    temp += n;
    total = temp;

    // Problematic Section ends
    std::cout << "Finished Problematic Section for n: " << n << std::endl;
}

int main() {
    ll n = 1000000000;
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); // start time
    std::thread t1(calculateSum, (ll)n); 
    std::thread t2(calculateSum, (ll)n+1);
    t1.join(); 
    t2.join();
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); // end time
    std::chrono::duration<double> elapsed = end - start; // time taken to call func twice
    std::cout << "Total: " << total << std::endl; // Expected total: 2000000001
    std::cout << "Time taken while using additional thread: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}