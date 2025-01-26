//https://codeforces.com/problemset/problem/723/A
// 723 A. The New Year: Meeting Friends


#include<bits/stdc++.h>
using namespace std;
int mas[3];
int main() {
    cin >> mas[0] >> mas[1] >> mas[2];
    sort(mas, mas + 3);
    cout << mas[2] - mas[0];
}