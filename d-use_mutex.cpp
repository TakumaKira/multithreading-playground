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

    std::cout << "Reached Problematic Section for n: " << n << std::endl;

    // Lock before modifying shared resource
    mtx.lock();

    std::cout << "Current total: " << total << ", n: " << n << std::endl;

    ll temp = total;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add a small delay
    temp += n;
    total = temp;

    // Problematic Section ends
    std::cout << "Finished Problematic Section for n: " << n << std::endl;

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