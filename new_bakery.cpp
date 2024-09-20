#include <iostream>
using namespace std;

void solve() {
    long long n, usual_price, modified_price;
    cin >> n >> usual_price >> modified_price;

   
    if (modified_price < usual_price) {
        cout << n * usual_price << endl;
    } else {
       
        long long num_modified_buns = min(n, modified_price - usual_price);
        
        long long num_usual_buns = n - num_modified_buns;
        
        long long last_modified_price = modified_price - num_modified_buns;
        long long max_profit = num_usual_buns * usual_price + (modified_price * (modified_price + 1) / 2) - (last_modified_price * (last_modified_price + 1) / 2);

        cout << max_profit << endl;
    }

    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
