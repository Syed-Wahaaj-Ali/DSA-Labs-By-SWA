#include <iostream>
#include <stack>
using namespace std;

// Syed Wahaaj Ali
// CT-24035

string buildString(string s) {
    stack<char> st;
    for (int i = 0; i < (int)s.length(); i = i + 1) {
        char c = s[i];
        if (c == '#') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    string result = "";
    for (int count = (int)st.size(); count > 0; count = count - 1) {
        char topChar = st.top();
        result = topChar + result;
        st.pop();
    }
    return result;
}

bool backspaceCompare(string s, string t) {
    return buildString(s) == buildString(t);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    if (backspaceCompare(s, t)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}
