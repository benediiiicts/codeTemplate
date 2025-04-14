#include <iostream>

using namespace std;

//fungsi berubah-ubah sesuai soal!!!
long func(long l, long z, long i, long m){
    return (z*l+i)%m;
}

int main(){
    long z, i, m;
    long l, count = 1;
    while(1){
        cin >> z >> i >> m >> l;
        if(z==0 && i==0 && m==0 && l==0) return 0;
        printf("Case %d: ", count++);
        // Phase 1: Find meeting point inside the cycle
        long tortoise = func(l, z, i, m);           // Tortoise moves once
        long hare = func(func(l, z, i, m), z, i, m); // Hare moves twice
        while(tortoise != hare){
            tortoise = func(tortoise, z, i, m);
            hare = func(func(hare, z, i, m), z, i, m);
        }
        // Phase 2: Find the start of the cycle (mu)
        // Reset tortoise to starting point, keep hare at meeting point
        int mu = 0;
        tortoise = l;  // Reset tortoise to starting point
        while(tortoise != hare){
            tortoise = func(tortoise, z, i, m);
            hare = func(hare, z, i, m);
            mu++;
        }
        // Phase 3: Find the length of the cycle (lambda)
        long lambda = 1;
        hare = func(tortoise, z, i, m);  // Move hare once
        while(tortoise != hare){
            hare = func(hare, z, i, m);
            lambda++;
        }
        cout << lambda << endl;
    }
}