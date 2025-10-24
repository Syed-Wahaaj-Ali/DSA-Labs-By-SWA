#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
   Syed Wahaaj Ali
   CT-24035
*/

class Solution {
private:
    int m, n;
    bool solve(int i, int x, int y, vector<vector<char>>& board, string& word) {
        if (i == word.size()) {
            return true;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[i]) {
            return false;
        }
        char temp = board[x][y];
        board[x][y] = '#';
        bool res = solve(i + 1, x + 1, y, board, word) || solve(i + 1, x - 1, y, board, word) ||
                   solve(i + 1, x, y + 1, board, word) || solve(i + 1, x, y - 1, board, word);
        board[x][y] = temp;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(0, i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    bool result1 = sol.exist(board1, word1);
    cout << "Example 1 Output: ";
    if (result1 == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Example 2
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "SEE";
    bool result2 = sol.exist(board2, word2);
    cout << "Example 2 Output: ";
    if (result2 == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // Example 3
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word3 = "ABCB";
    bool result3 = sol.exist(board3, word3);
    cout << "Example 3 Output: ";
    if (result3 == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
