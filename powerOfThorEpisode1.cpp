#include <iostream>

using namespace std;

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();

        string dir;
        int norm_x = light_x - initial_tx; 
        int norm_y = light_y - initial_ty;

        norm_x = norm_x > 0 ? 1 : (norm_x < 0 ? -1 : 0);
        norm_y = norm_y > 0 ? 1 : (norm_y < 0 ? -1 : 0);
        
        if (norm_x == 1) {
            dir = norm_y == 1 ? "SE" : (norm_y == -1 ? "NE" : "E");
        } 
        else if (norm_x == -1) {
            dir = norm_y == 1 ? "SW" : (norm_y == -1 ? "NW" : "W");
        }
        else {
            dir = norm_y == 1 ? "S" : "N";
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << dir << endl;

        initial_tx += norm_x;
        initial_ty += norm_y;
    }
}
