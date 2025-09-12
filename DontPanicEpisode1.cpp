// Problem: https://www.codingame.com/ide/puzzle/don't-panic-episode-1

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int nb_floors;
    int width;
    int nb_rounds;
    int exit_floor;
    int exit_pos;
    int nb_total_clones;
    int nb_additional_elevators;
    int nb_elevators;

    cin >> nb_floors >> width >> nb_rounds >> exit_floor
        >> exit_pos >> nb_total_clones >> nb_additional_elevators
        >> nb_elevators;
    cin.ignore();

    map<int, int> elevators;
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor;
        int elevator_pos;
        cin >> elevator_floor >> elevator_pos;
        cin.ignore();
        elevators[elevator_floor] = elevator_pos;
    }

    // game loop
    while (1) {
        int clone_floor;
        int clone_pos;
        string direction;
        cin >> clone_floor >> clone_pos >> direction;
        cin.ignore();

        // If no leading clone, wait
        if (clone_floor == -1) {
            cout << "WAIT" << endl;
            continue;
        }

        // Determine target position based on current position
        int target_pos;
        if (clone_floor == exit_floor) {
            target_pos = exit_pos;
        } else {
            target_pos = elevators.at(clone_floor);
        }

        // Block if moving away from target
        if ((direction == "RIGHT" && clone_pos > target_pos) ||
            (direction == "LEFT"  && clone_pos < target_pos)) {
            cout << "BLOCK" << endl;
        } else {
            cout << "WAIT" << endl;
        }
    }
}
