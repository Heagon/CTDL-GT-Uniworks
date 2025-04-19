#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string prepareText(string text) {
    string preparedText = "";
    for (char c : text) {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') {
                preparedText += 'I';
            } else {
                preparedText += c;
            }
        }
    }

    string result = "";
    for (int i = 0; i < preparedText.length(); i += 2) {
        result += preparedText[i];
        if (i + 1 < preparedText.length()) {
            if (preparedText[i] == preparedText[i + 1]) {
                if (preparedText[i] == 'X') {
                    result += 'Q';
                } else {
                    result += 'X';
                }
                result += preparedText[i + 1];
            } else {
                result += preparedText[i + 1];
            }
        } else {
            result += 'X';
        }
    }
    return result;
}

vector<vector<char>> createMatrix(string key) {
    vector<vector<char>> matrix(5, vector<char>(5));
    string keyString = "";
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for (char c : key) {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I';
            if (keyString.find(c) == string::npos) {
                keyString += c;
            }
        }
    }

    for (char c : alphabet) {
        if (keyString.find(c) == string::npos) {
            keyString += c;
        }
    }

    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = keyString[k++];
        }
    }
    return matrix;
}

pair<int, int> findChar(const vector<vector<char>>& matrix, char c) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == c) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

string playfairEncrypt(string text, string key) {
    string preparedText = prepareText(text);
    vector<vector<char>> matrix = createMatrix(key);
    string ciphertext = "";

    for (int i = 0; i < preparedText.length(); i += 2) {
        char char1 = preparedText[i];
        char char2 = preparedText[i + 1];

        pair<int, int> pos1 = findChar(matrix, char1);
        pair<int, int> pos2 = findChar(matrix, char2);

        int row1 = pos1.first;
        int col1 = pos1.second;
        int row2 = pos2.first;
        int col2 = pos2.second;

        if (row1 == row2) {
            ciphertext += matrix[row1][(col1 + 1) % 5];
            ciphertext += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext += matrix[(row1 + 1) % 5][col1];
            ciphertext += matrix[(row2 + 1) % 5][col2];
        } else {
            ciphertext += matrix[row1][col2];
            ciphertext += matrix[row2][col1];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    string key;

    cout << "Nhap ban ro: ";
    getline(cin, plaintext);

    cout << "Nhap khoa: ";
    getline(cin, key);

    string ciphertext = playfairEncrypt(plaintext, key);
    cout << "Ban ma: " << ciphertext << endl;

    return 0;
}