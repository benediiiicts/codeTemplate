#include <iostream>
#include <vector>

using namespace std;
vector<int> result;
int k;

// Function to process and print the current k-ary string
void process() {
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
    }
    std::cout << std::endl;
}

// Recursive function to generate k-ary strings
void generateKAryStringRek(int curIdx) {
    if (curIdx == -1) {
        process();
    } else {
        for (int i = 0; i < k; i++) {
            result[curIdx] = i;
            generateKAryStringRek(curIdx - 1);
        }
    }
}

// Function to initialize and start the k-ary string generation
void generateKAryString() {
    generateKAryStringRek(result.size() - 1);
}

// Initialize the parameters for k-ary string generation
void initKAryString(int length, int kValue) {
    result.resize(length);
    k = kValue;
}

int main() {
    // Equivalent to KAryString kas = new KAryString(5, 4);
    initKAryString(5, 4);
    
    // Generate k-ary strings
    generateKAryString();
    
    return 0;
}