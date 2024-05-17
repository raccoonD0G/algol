#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = 0;
        if (i >= 0) {
            digit1 = num1[i] - '0';
            i--;
        }

        int digit2 = 0;
        if (j >= 0) {
            digit2 = num2[j] - '0';
            j--;
        }

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

void BuildCArr(vector<vector<string>>& CArr) {
    for (int i = 0; i < CArr.size(); i++) {
        for (int j = 0; j < CArr[0].size() && j <= i; j++) {
            if (j == 0 || j == i) {
                CArr[i][j] = "1";
            } else {
                CArr[i][j] = addStrings(CArr[i - 1][j - 1], CArr[i - 1][j]);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<string>> CArr(n + 1, vector<string>(k + 1, "0"));
    BuildCArr(CArr);

    cout << CArr[n][k];

    return 0;
}
