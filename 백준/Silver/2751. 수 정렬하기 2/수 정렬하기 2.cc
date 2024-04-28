#include <iostream>
#include <vector>
#include <algorithm> // std::swap 함수 사용을 위해 포함

using namespace std;

void QuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 3;
    swap(arr[left], arr[mid]);
    int pivot = left;

    int i = left + 1;
    int j = right - 1;
    while (true) {
        for (; i < right; i++) {
            if (arr[pivot] < arr[i]) break;
        }
        for (; j > left; j--) {
            if (arr[pivot] > arr[j]) break;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    swap(arr[pivot], arr[j]);
    QuickSort(arr, left, j);
    QuickSort(arr, j + 1, right);
}

int main() {
    ios::sync_with_stdio(false); // C++ 표준 스트림과 C 스타일 스트림의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 tie를 끊음

    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    QuickSort(numbers, 0, N);

    for (int number : numbers) {
        cout << number << "\n";
    }

    cout.flush(); // 모든 출력을 확실히 보내기 위해 flush 호출
    return 0;
}
