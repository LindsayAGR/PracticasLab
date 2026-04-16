#include "rle.h"
#include <cctype>

string compressRLE(const string& input) {
    string result = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        result += to_string(count) + input[i];
    }

    return result;
}

string decompressRLE(const string& input) {
    string result = "";

    for (int i = 0; i < input.length(); i++) {
        int count = 0;

        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        char c = input[i];

        for (int j = 0; j < count; j++) {
            result += c;
        }
    }

    return result;
}
