#include <iostream>
#include <iomanip>
#include <conio.h>
#include <random>

#include "Variables.h"
#include "define_points.h"

using namespace std;


random_device rd; //These two lines are a random function
uniform_int_distribution<int> rand_(0, 6); /*A bit difficult to get
                                           why we're using it like this
                                           because rand() didn't help me*/

                                           /*
                                               | I'm using random numbers to |
                                               | set the next coordinates of |
                                               | an animatronic right after  |
                                               | You've locked the door in   |
                                               | front of its.               |
                                           */

auto clean_screen = []() {
    system("cls");
    };

void map(short& x_b, short& y_b, short x_c, short y_c, bool& isLeft, bool& isRight, float& energy_value, int& hours, char& rate) {

    /*
        | before you look at this code.     |   До того, как увидеть код,       |
        | pls, don't judge me.              |   Прошу не бейте меня.            |
        | I'm learning C++ only             |   Я учу С++ только третью неделю  |
        | third week. Thanks! ^_^           |   Спасибо! ^_^                    |

                                                                                                  */
                                                                                                  /*

                                                                                                      | ok, let's talk. The array "map_frame_array" |
                                                                                                      | contains a whole map. I've made this just   |
                                                                                                      | to change the small piece of the map when   |
                                                                                                      | animatronics are changing their positions.  |

                                                                                                                                                                                                  */



    string map_frame_array[]{ "                         ____________________                               ",
                        "                        |                    |                              ",
                        "                        |                    |                              ",
                        "                        |                    |                              ",
                        " ______    _____________|         *          |________________              ",
                        "|      |__|                                                   |             ",
                        "|                                                             |   ____      ",
                        "|       __                                                    |  |    |     ",
                        "|      |  |                                                   |  |    |     ",
                        "|      |  |                                                   |__|    |     ",
                        "|      |  |                                                           |     ",
                        "|      |  |                                                    __     |     ",
                        "|______|  |                                                   |  |    |     ",
                        "    ______|                                                   |  |    |     ",
                        "   |                                                          |  |    |     ",
                        "   |                                                          |  |    |     ",
                        "   |  *                                                       |  |    |     ",
                        "   |                                                          |  |    |     ",
                        "   |______                                                    |  |    |     ",
                        "          |__________     _________________      ________   __|  |____|     ",
                        "                 ____|   |____         ____|    |___    |   |______________ ",
                        "                |             |       |             |   |                  |",
                        "      _______   |             |       |             |   |                  |",
                        "     |       |  |             |       |             |   |                  |",
                        "     |       |  |             |       |             |   |                  |",
                        "     |       |__|             |       |             |   |                  |",
                        "     |                        |       |             |   |                  |",
                        "     |        __              |       |             |   |__________________|",
                        "     |       |  |             |       |             |                       ",
                        "     |       |  |             |       |             |                       ",
                        "     |_______|  |             |       |             |                       ",
                        "                |             |_______|             |                       ",
                        "                |             |       |             |                       ",
                        "                |                                   |                       ",
                        "                |                 *                 |                       ",
                        "                |_____________|_______|_____________|                       " };

    /*
        | The next 4 conditions are going to check    |
        | which doors are going to be locked.         |
        | It depends on which button you've pressed   |
        | in "receive_the_button" function.           |

        | There's a rate sign to know how mush energy |
        | you've spent. There's no cameras in this    |
        | prototype, so you can only use more energy  |
        | to close the doors and this conditions are  |
        | changing the sign because we know how much  |
        | energy we're using.                         |

    */


    if (isLeft && !(isRight)) {
        map_frame_array[33] = "                |             |                     |                       ";
        map_frame_array[34] = "                |             |   *                 |                       ";
        rate = 'B';
    }
    else if (!(isLeft) && isRight) {
        map_frame_array[33] = "                |                     |             |                       ";
        map_frame_array[34] = "                |                 *   |             |                       ";
        rate = 'B';
    }
    else if (isLeft && isRight) {
        map_frame_array[33] = "                |             |       |             |                       ";
        map_frame_array[34] = "                |             |   *   |             |                       ";
        rate = 'A';
    }
    else if (!(isLeft) && !(isRight)) {
        map_frame_array[33] = "                |                                   |                       ";
        map_frame_array[34] = "                |                 *                 |                       ";
        rate = 'C';
    }

    /*
        | Maybe I could use <windows.h>    |
        | but I was just using <iomanip>   |
        | every time.                      |

        | The next loop is going to make   |
        | 20 new line indentions.          |

    */

    for (size_t i{}; i < 20; ++i) {
        cout << endl;
    }


    /*
        | Again the next loop is going to change    |
        | the "map_frame_array" element exactly     |
        | in a place where we have an animatronic's |
        | coordinates.                              |
        | This method isn't so unique 'cause if I'd |
        | add Foxy and Freddy to this game, then    |
        | I needed to write two more conditions.    |
    */

    for (size_t i{}; i < size(map_frame_array); ++i) {
        if (y_b == i) {

            for (size_t j{}; j < size(map_frame_array[y_b]); ++j) {
                if (x_b == j) {
                    map_frame_array[y_b][j] = '*';
                }
            }
        }
        if (y_c == i) {

            for (size_t j{}; j < size(map_frame_array[y_c]); ++j) {
                if (x_c == j) {
                    map_frame_array[y_c][j] = '*';
                }
            }
        }

    }


    //This loop just printing everything from "map_frame_array".
    for (auto frame : map_frame_array) {
        cout << setw(51) << " " << frame << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    /*
        | The next lines are printing a few tips:                   |
        |                                                           |
        | 1. How to close/open the doors (left/right);              |
        | 2. How much energy you have and how fast you're using it; |
        | 3. How many hours have passed.                            |
    */

    cout << setw(51) << " " << "Q - close/Open the left door" << " " << setw(33) << energy_value << "%" << endl;
    cout << setw(51) << " " << "E - close/Open the right door" << " " << setw(31) << hours << "AM" << endl;
    cout << setw(51) << " " << "Energy amount : " << rate << endl;
}

void receive_the_button(bool& isLeft, bool& isRight) {

    /*

            | the function is receiving |
            |    which is obvious       |
            |      the keyboard and     |
            |  locking the doors        |
            |                           |       */

    if (_kbhit()) { //replace "_kbhit()" with "kbhit()" as well if there's some problem
        switch (_getch()) {
            //   | if you have a compiler error       |
            //   | on this line of code, then         |
            //   | you can try and replace "_getch()" |
            //   | with "getch()". Sorry for that!    |
        case 'q':

            if (isLeft)
                isLeft = false;
            else
                isLeft = true;

            break;
        case 'e':

            if (isRight)
                isRight = false;
            else
                isRight = true;

            break;
        default:

            break;
        }
    }
}

void bonnie_logic(short& x_b, short& y_b, int& b_steps, bool& isLeft) {

    /*
        | File "main.cpp" has all variables and "b_steps" var as well.    |
        | "b_steps" var is an int variable which changes after new call   |
        | If "b_steps" has changed, then the coordinates are going to     |
        | be replaced with another ones.                                  |
        | Right here we are using random number to know where an          |
        | animatronic is going to after he was "rejected" by the door)    |
    */


    if (b_steps == 1) {
        x_b = dining_room_x_b;
        y_b = dining_room_y_b;
    }
    else if (b_steps == 2) {
        x_b = storage_x_b;
        y_b = storage_y_b;
    }
    else if (b_steps == 3) {
        x_b = west_hallway_x_b;
        y_b = west_hallway_y_b;
    }
    else if (b_steps == 4) {
        x_b = service_space_x_b;
        y_b = service_space_y_b;
    }
    else if (b_steps == 5) {
        x_b = corner_west_hallway_x_b;
        y_b = corner_west_hallway_y_b;
    }
    else if (b_steps == 6) {
        x_b = at_the_office_admission_x_b;
        y_b = at_the_office_admission_y_b;
    }
    else if (b_steps == 7) {

        if (isLeft) {
            b_steps = rand_(rd); //Right here we're using random numbers
        }
        else {
            b_steps = 10; // If b_steps is 10, then it's a sign to stop the main loop


        }
    }
}

void chica_logic(short& x_c, short& y_c, int& c_steps, bool& isRight) {

    /*
        | File "main.cpp" has all variables and "c_steps" var as well.          |
        | "b_steps" var is an int variable which changes after new call         |
        | If "b_steps" has changed, then the coordinates are going to           |
        | be replaced with another ones.                                        |
        | Right here we are using random number to know where an                |
        | animatronic is going to after he was "rejected" by the door)          |
        |                                                                       |
        | And Yes! I just copied the last comments in "bonnie_logic function.)" |
    */


    if (c_steps == 1) {
        x_c = dining_room_x_c;
        y_c = dining_room_y_c;
    }
    else if (c_steps == 2) {
        x_c = wash_room_x_c;
        y_c = wash_room_y_c;
    }
    else if (c_steps == 3) {
        x_c = dining_room_x_c;
        y_c = dining_room_y_c;
    }
    else if (c_steps == 4) {
        x_c = kitchen_x_c;
        y_c = kitchen_y_c;
    }
    else if (c_steps == 5) {
        x_c = dining_room_x_c;
        y_c = dining_room_y_c;
    }
    else if (c_steps == 6) {
        x_c = east_hallway_x_c;
        y_c = east_hallway_y_c;
    }
    else if (c_steps == 7) {
        x_c = corner_east_hallway_x_c;
        y_c = corner_east_hallway_y_c;
    }
    else if (c_steps == 8) {
        x_c = at_the_office_admission_x_c;
        y_c = at_the_office_admission_y_c;
    }
    else if (c_steps == 9) {
        if (isRight) {
            c_steps = rand_(rd); //And right here we're using random numbers as well
        }
        else {
            c_steps = 10; // If c_steps is 10, then it's a sign to stop the main loop as well
        }
    }
}

