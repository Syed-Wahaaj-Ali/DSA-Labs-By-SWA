#include <iostream>
#include <queue>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class DataStream {
    int value;    // value we care about tracking
    int k;        // how many consecutive times
    int count;    // how many times in current window match the value
    queue<int> q; // last k numbers seen

public:
    DataStream(int val, int num) {
        value = val;
        k = num;
        count = 0;
    }

    bool consec(int num) {
        q.push(num);

        if (num == value) 
            count++;    // found a matching number, increment count
        
        if (q.size() > k) {
            int front = q.front();
            q.pop();
            if (front == value) 
                count--; // lost a matching number from the window
        }

        if (q.size() < k) return false;  // still don't have k numbers yet
        return count == k;               // true only if all last k numbers match
    }
};

int main() {
    DataStream dataStream(4, 3);

    if (dataStream.consec(4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    if (dataStream.consec(4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    if (dataStream.consec(4)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    if (dataStream.consec(3)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

