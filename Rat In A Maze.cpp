#include <iostream>
#include <vector>
#include <string>

using namespace std;

void posi(vector<vector<int>> &maze, int &ans, int row, int col, string path,
     vector<string> &anas)
{
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || 
            maze[row][col] == 0 || maze[row][col] == -1)
    {
        return;
    }
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        ans++;
        anas.push_back(path);
        return;
    }

    maze[row][col] = -1;
    posi(maze, ans, row + 1, col, path + "D", anas);
    posi(maze, ans, row - 1, col, path + "U", anas);
    posi(maze, ans, row, col + 1, path + "R", anas);
    posi(maze, ans, row, col - 1, path + "L", anas);
    maze[row][col] = 1;
}

int main()
{
    vector<vector<int>> maze{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int ans = 0;
    vector<string> anas;
    string path = "";
    posi(maze, ans, 0, 0, path, anas);
    for (auto val : anas)
    {
        cout << val <<endl;
    }
    cout << endl;
    cout << "no. of paths : " << ans;
}