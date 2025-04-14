#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

// Function to process and print the current bit string
void process() {
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
    }
    std::cout << std::endl;
}

// Recursive function to generate bit strings
void generateBitStringRek(int curIdx) {
    if (curIdx == -1) {
        process();
    } else {
        result[curIdx] = 0;
        generateBitStringRek(curIdx - 1);
        
        result[curIdx] = 1;
        generateBitStringRek(curIdx - 1);
    }
}

// Function to initialize and start the bit string generation
void generateBitString() {
    generateBitStringRek(result.size() - 1);
}

// Initialize the parameters for bit string generation
void initBitString(int n) {
    result.resize(n);
}

int main() {
    // Equivalent to BitString bs = new BitString(9);
    initBitString(9);
    
    // Generate bit strings
    generateBitString();
    
    return 0;
}