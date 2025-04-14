#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
int n;

// Function to process and print the current combination
void process() {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}

// Recursive function to generate combinations
void generateKombinasiRek(int iStartValue, int curIdx) {
    if (curIdx == result.size()) {
        process();
    } else {
        for (int i = iStartValue; i <= n - result.size() + curIdx + 1; i++) {
            result[curIdx] = i;
            generateKombinasiRek(i + 1, curIdx + 1);
        }
    }
}

// Function to initialize and start the combination generation
void generateKombinasi() {
    generateKombinasiRek(1, 0);
}

// Initialize the parameters for combination generation
void initKombinasi(int nValue, int length) {
    result.resize(length);
    n = nValue;
}

int main() {
    // Equivalent to Kombinasi k = new Kombinasi(5, 2);
    initKombinasi(5, 2);
    
    // Generate combinations
    generateKombinasi();
    
    return 0;
}