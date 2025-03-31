#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPos(vector<string>& board, int n, int col, int r) {
    for (int i = 0; i < n; i++) {
        if (board[r][i] == 'Q') {
            return false;
        }
    }
    for (int i = 0; i < r; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    int rl = r;
    int cl = col;
    while (rl >= 0 && cl >= 0) {
        if (board[rl][cl] == 'Q') {
            return false;
        }
        rl--;
        cl--;
    }
    int rr = r;
    int cr = col;
    while (rr >= 0 && cr < n) {
        if (board[rr][cr] == 'Q') {
            return false;
        }
        rr--;
        cr++;
    }
    return true;
}

void isValid(vector<string>& board, vector<vector<string>>& ans, int n, int r){
    if(r == n){
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isPos(board, n, i ,r)){
            board[r][i] = 'Q';
            isValid(board, ans, n, r+1);
            board[r][i] = '.';
        }
    }
}

int main(){
    int n = 4;
    int r = 0;
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;
    isValid(board, ans, n, r);

    for(auto str : ans){
        for(auto s : str){
            cout << s;
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}