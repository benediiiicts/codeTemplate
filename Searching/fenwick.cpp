#include <bits/stdc++.h>
 
 using namespace std;
 
 vector<int> fenwick;
 int n;
 
 void update(int idx, int val) {
     while (idx <= n) {
         fenwick[idx] += val;
         idx += (idx & -idx);
     }
 }
 
 int query(int idx) {
     int sum = 0;
     while (idx > 0) {
         sum += fenwick[idx];
         idx -= (idx & -idx);
     }
     return sum;
 }
 
 int rangeQuery(int left, int right) {
     return query(right) - query(left - 1);
 }
 
 void buildFenwick(vector<int>& arr) {
     n = arr.size();
     fenwick.resize(n + 1, 0);
     for (int i = 0; i < n; i++) {
         update(i + 1, arr[i]);
     }
 }
 
 int main() {
     vector<int> arr = {3, 2, 5, 1, 7, 9, 4};
     buildFenwick(arr);
     cout << "Original Array: ";
     for (int val : arr) {
         cout << val << " ";
     }
     cout << endl;
     cout << "Sum of elements from index 1 to 5: " << rangeQuery(1, 5) << endl;
     cout << "Sum of elements from index 2 to 6: " << rangeQuery(2, 6) << endl;
     cout << "Updating value at index 3, adding 4" << endl;
     update(3, 4);
     cout << "Sum of elements from index 1 to 5 after update: " << rangeQuery(1, 5) << endl;
     return 0;
 }