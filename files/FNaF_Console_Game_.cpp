#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "Functions.h"

using namespace std;

int main()
{

    int iterations{}; /* | This variables can help to understand     |
                         | how many seconds passed. We're not going  |
                         | to know the passed time directly but      |
                         | approximately.                            |
                                                                        */


    char rate_of_energy_amount{ 'C' };

    float energy{ 100 };


    int hours{ 0 }; /*
                    | There's some mistake 'cause at the beginning  |
                    | you'll see that it's 0AM but not 12AM.        |
                    | I've not made it correctly.                   |
                    | Sorry for not making this detail.             |

                    */


                    // | From "variables.h" we've created variables from here |
    Coord::Bonnie_pos bonnie_struct;
    bonnie_struct.x = 29;
    bonnie_struct.y = 3;
    int b_steps{ 0 };

    Coord::Chica_pos chica_struct;
    chica_struct.x = 40;
    chica_struct.y = 3;
    int c_steps{ 0 };

    Coord::Doors doors;
    doors.isLeft = false;
    doors.isRight = false;
    // | To here |

 /*
    | The while loop is the main loop.  |
    | The loop is updating the map      |
    | in 30 FPS, almost.                |
    | You have the opportunity of       |
    | pressing some buttons and then    |
    | the map is going to change itself |
    | in a half second (almost).        |
 */

    while (true) /* THE MAIN LOOP */ {
        std::this_thread::sleep_for(0.033s); /*

            | If 30 FPS is 30 updates in 1 second           |
            | then I can tell that 30 frames is going to be |
            | 30 iterations of the main loop.               |
            | One iteration is gonna be in 0.0333 seconds   |
            | because 1s / 30 = 0.0333s.                    |

        */

        /*
                | The next 2 conditions are going to check                  |
                | if it's 6AM and breaking the main loop.                   |
                | Otherwise it's the moment when "b_steps" or "c_steps"     |
                | are 10 which means that one of them has killed the player |
                | and we can break the main loop.                           |
        */

        if (hours == 6) {
            cout << setw(51) << " " << "Congrats, you won)" << endl;
            break;
        }
        if (b_steps == 10 || c_steps == 10) {
            cout << setw(51) << " " << "You're dead" << endl;
            break;
        }



        ++iterations; //60 is in theory, 7 or 8 seconds. 30s - 270 //60 - 10s - 1%  1000 / 60 = 0.016
        //if C - 0.016 / frame; if B - 0.032 / 1 frame; if A - 0.048
        //360 - 1 hour
        clean_screen();

        if (_kbhit() && energy > 0) { /*    | The function "_kbhit is going to find out if we pressed the button"    |
                                            | and only if there's some energy we can open or locked the doors        |
                                            | in "receive_the_button" function.                                      |

                                                                                                                    */
            receive_the_button(doors.isLeft, doors.isRight);
        }

        if (iterations % 68 == 0) { //Every 68 updates the condition is changing the position of Chica
            c_steps += 1;
            chica_logic(chica_struct.x, chica_struct.y, c_steps, doors.isRight);

        }
        if (iterations % 89 == 0) { //Every 89 updates the condition is changing the position of Bonnie
            b_steps += 1;
            bonnie_logic(bonnie_struct.x, bonnie_struct.y, b_steps, doors.isLeft);

        }
        if (iterations % 360 == 0) { //360 updates almost are gonna be 1 minute.
            hours += 1;
        }

        /*
                | The few condions are checking how much energy                 |
                | we need to take away. There's a rule in the original game     |
                | that you're using energy to survive and you need to organize  |
                | you energy consumption.                                       |
        */
        if (energy > 0) {
            if (rate_of_energy_amount == 'C')
                energy -= 0.025f;
            else if (rate_of_energy_amount == 'B')
                energy -= 0.05f;
            else if (rate_of_energy_amount == 'A')
                energy -= 0.075f;
        }
        else if (energy <= 0) {
            energy = 0;
            doors.isLeft = false;
            doors.isRight = false;
        }

        map(bonnie_struct.x, bonnie_struct.y, chica_struct.x, chica_struct.y, doors.isLeft, doors.isRight, energy, hours, rate_of_energy_amount);
    }
    return 0;
}

