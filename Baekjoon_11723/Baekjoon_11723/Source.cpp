#include <iostream>
#include <cstring>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string prompt;
    int M, num;

    int S = 0;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> prompt;

        if (prompt == "add") {
            cin >> num;
            S = (S | (1 << num));
        }

        else if (prompt == "remove") {
            cin >> num;
            S &= ~(1 << num);
        }
        else if (prompt == "check") {
            cin >> num;
            if (S & (1 << num)) {   
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (prompt == "toggle") {
            cin >> num;
            if (S & (1 << num)) {  
                S &= ~(1 << num); 
            }
            else {             
                S |= (1 << num);     
            }
        }
        else if (prompt == "all") {
            S = (1 << 21) - 1;
        }
        else if (prompt == "empty") {
            S = 0;
        }


    }

    return 0;
}
