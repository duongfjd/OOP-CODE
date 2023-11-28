#include<bits/stdc++.h> 
using namespace std; 
class SequencePrinter {
public:
    SequencePrinter(long n, long S) : n(n), S(S) {
        R = (n + 1) * n / 2;
        L = 2 - R;
    }

    void printSequence() {
        if ((S + R) % 2) {
            cout << "Impossible";
        } else if (!check(L, R, S)) {
            cout << "Impossible";
        } else {
            print(L, R, n, S);
        }
    }

private:
    long n, S, L, R;

    bool check(long L, long R, long S) {
        return !(S > R || S < L || S == R - 2 || S == L + 2);
    }

    void print(long L, long R, long n, long S) {
        if (n == 1) {
            cout << "1";
            return;
        }
        if (check(L + n, R - n, S - n)) {
            print(L + n, R - n, n - 1, S - n);
            cout << "+" << n;
        } else {
            print(L + n, R - n, n - 1, S + n);
            cout << "-" << n;
        }
    }
};

int main() {
    long n, S;
    cin >> n >> S;
    SequencePrinter sequencePrinter(n, S);
    sequencePrinter.printSequence();

    return 0;
}

