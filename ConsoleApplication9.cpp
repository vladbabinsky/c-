#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nMinimum element: " << min << "\n";
    cout << "Maximum element: " << max << "\n";
}


//#----- TASK 2 -----#

#include <iostream>

using namespace std;

int main() {
    const int MONTHS = 12;
    int profits[MONTHS] = { 3000, 3500, 4000, 6000, 5500, 3000, 4800, 4700, 5500, 5200, 6200, 7000 };

    int maxProfit = profits[0], minProfit = profits[0];
    int maxMonth = 0, minMonth = 0;

    for (int i = 1; i < MONTHS; ++i) {
        if (profits[i] > maxProfit) {
            maxProfit = profits[i];
            maxMonth = i;
        }
        if (profits[i] < minProfit) {
            minProfit = profits[i];
            minMonth = i;
        }
    }

    cout << "Maximum profit: " << maxProfit << " in month " << maxMonth + 1 << "\n";
    cout << "Minimum profit: " << minProfit << " in month " << minMonth + 1 << "\n";
}

//#----- TASK 3 -----#
#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    double arr[N] = { -3.5, 6.2, -1.1, 8.4, -4.0, 2.3, 5.5, -9.7, 3.3, -6.6 };

    double sumEven = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == int(arr[i]) && int(arr[i]) % 2 == 0) {
            sumEven += arr[i];
        }
    }

    double product = 1;
    double min = arr[0], max = arr[0];
    int minIdx = 0, maxIdx = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIdx = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }

    if (minIdx > maxIdx) {
        swap(minIdx, maxIdx);
    }

    for (int i = minIdx + 1; i < maxIdx; i++) {
        product *= arr[i];
    }

    double productEvenPos = 1;
    for (int i = 0; i < N; i += 2) {
        productEvenPos *= arr[i];
    }

    double sumBetweenEven = 0;
    int firstEven = -1, lastEven = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] == int(arr[i]) && int(arr[i]) % 2 == 0) {
            if (firstEven == -1) {
                firstEven = i;
            }
            lastEven = i;
        }
    }

    if (firstEven != -1 && lastEven != -1 && firstEven != lastEven) {
        for (int i = firstEven + 1; i < lastEven; i++) {
            sumBetweenEven += arr[i];
        }
    }

    cout << "Sum of even integer elements: " << sumEven << endl;
    cout << "Product between min and max: " << product << endl;
    cout << "Product of elements at even positions: " << productEvenPos << endl;
    cout << "Sum between first and last even integer elements: " << sumBetweenEven << endl;
}

