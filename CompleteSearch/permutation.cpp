#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
vector<bool> mark;

// Function to process and print the current permutation
void process() {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}

// Recursive function to generate permutations
void generatePermutasiRek(int curIdx) {
    if (curIdx == -1) {
        process();
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (mark[i] == true) {
                mark[i] = false;
                result[curIdx] = i;
                generatePermutasiRek(curIdx - 1);
                mark[i] = true;
            }
        }
    }
}

// Function to initialize and start the permutation generation
void generatePermutasi() {
    // Initialize all marks to true
    for (int i = 0; i < mark.size(); i++) {
        mark[i] = true;
    }
    
    // Start recursive permutation generation
    generatePermutasiRek(result.size() - 1);
}

// Initialize the parameters for permutation generation
void initPermutasi(int n) {
    result.resize(n);
    mark.resize(n);
}

int main() {
    // Equivalent to Permutasi p = new Permutasi(3);
    initPermutasi(3);
    
    // Generate permutations
    generatePermutasi();
    
    return 0;
}