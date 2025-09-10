#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int w; // the number of cells on the X axis
    cin >> w; cin.ignore();
    int h; // the number of cells on the Y axis
    cin >> h; cin.ignore();

    vector<vector<string>> points(h, vector<string>(w));

    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);

        for (size_t j = 0; j < line.length(); j++) {
            if (line[j] != '.') {
                string pos = to_string(j) + " " + to_string(i);
                points[i][j] = pos;
            } else {
                points[i][j] = "";
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (points[i][j].empty()) {
                continue;
            }
            cout << points[i][j] << " ";

            // Find right neighbor
            int curr_j = j + 1;
            while (curr_j < w && points[i][curr_j].empty()) {
                curr_j++;
            }
            if (curr_j < w) {
                cout << points[i][curr_j] << " ";
            } else {
                cout << "-1 -1 ";
            }

            // Find bottom neighbor
            int curr_i = i + 1;
            while (curr_i < h && points[curr_i][j].empty()) {
                curr_i++;
            }
            if (curr_i < h) {
                cout << points[curr_i][j] << "\n";
            } else {
                cout << "-1 -1\n";
            }
        }
    }

    return 0;
}
