#include <iostream>
using namespace std;

int count1 = 0;
int count0 = 0;

int main() {

    int T;
    int N;

    int fibonacci[41][2] = { 0, };

    fibonacci[0][0] = 1;
    fibonacci[0][1] = 0;

    fibonacci[1][0] = 0;
    fibonacci[1][1] = 1;

    for (int i = 2; i < 41; i++) {
        fibonacci[i][0] = fibonacci[i - 1][0] + fibonacci[i - 2][0];
        fibonacci[i][1] = fibonacci[i - 1][1] + fibonacci[i - 2][1];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << fibonacci[N][0] << ' ' << fibonacci[N][1] << endl;
    }


    return 0;
}