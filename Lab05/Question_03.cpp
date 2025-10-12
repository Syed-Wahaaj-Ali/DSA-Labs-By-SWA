#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class Call {
public:
    int callID;
    string arrivalTime;
    string customerName;

    Call(int id, string time, string name) {
        callID = id;
        arrivalTime = time;
        customerName = name;
    }
};

class CallCenter {
private:
    queue<Call> callQueue;
    int numCSR;
    vector<bool> csrAvailable;

public:
    CallCenter(int n) {
        numCSR = n;
        csrAvailable = vector<bool>(n, true);  // all CSRs start free
    }

    void addCall(Call c) {
        callQueue.push(c);
        cout << "New call added: " << c.customerName << " (Call ID: " << c.callID << ")\n";
    }

    void processCalls() {
        while (!callQueue.empty()) {
            bool assignedAny = false;
            for (int i = 0; i < numCSR && !callQueue.empty(); i++) {
                if (csrAvailable[i]) {
                    Call current = callQueue.front();
                    callQueue.pop();

                    csrAvailable[i] = false; // CSR busy now

                    cout << "\nCSR " << i + 1 << " is handling call " << current.callID << " from " << current.customerName << "\n";

                    // Simulate finishing the call instantly
                    cout << "CSR " << i + 1 << " finished call from " << current.customerName << " and is now free.\n";
                    csrAvailable[i] = true;  // CSR free again

                    assignedAny = true;
                } else {
                    cout << "CSR " << i + 1 << " is busy\n";
                }
            }

            if (!assignedAny) {
                cout << "\nAll CSRs are busy, waiting for next available...\n";
                // In real scenario, we will here until a CSR frees up
            }
        }

        cout << "\nAll calls have been handled successfully!\n";
    }
};

int main() {
    CallCenter center(3);

    center.addCall(Call(1, "10:00", "Ali"));
    center.addCall(Call(2, "10:02", "Zain"));
    center.addCall(Call(3, "10:05", "Abdullah"));
    center.addCall(Call(4, "10:08", "Zainab"));
    center.addCall(Call(5, "10:10", "Ayesha"));

    center.processCalls();
    return 0;
}
