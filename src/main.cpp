#include "../include/game_loop.h"

/*! \mainpage Magos Index Page
 * \section intro_sec Introduction
 *
 * **Wellcome to MAGOS Project.**
 * This is a maze genarator solve (MAGOS) Program:
 * The magos creates an MAze on canvas build and solve is two way first Backtrack and left hand by your choice.
 *
 * \section install_sec Run
 *
 * \subsection step1 Step 1: Make ./magos
 *
 * g++ -Wall -std=c++11 src/main.cpp src/canvas.cpp src/render.cpp src/build.cpp src/solve.cpp src/game_loop.cpp -I include/ -o magos
 *
 * \subsection step2 Step 2: Run ./magos
 *
 * Dont forgot rows(2x3), colums(3x2), width(100x100) and height(100x100).
 * ./keno data/bet.dat 40, 60, 1200, 800
 *  lower configuration (2x3) or (3x2) and (100x100).
 * On class Build you can choose how much map can be random, if the map is to big
 * can take to long time to build because the cell are pick randomly to fix this
 * can set percent random to 40%.
 *
 * Left-hand Solve on this setup the the alway will begin face the north and your left
 * hand on left every time them is not have free pass to front we will turn to clockwise.
 *
 * \subsection step3 Step 3: Magos Running
 *
 * when magos start image will be creates on specific folder.
 *
 * \subsection step4 Step 4: Author
 *
 * @author Bergony Bandeira
 *
 * @date 05/12/2018
 */

int main ( int argc, char **argv )
{

    //!  @brief This is a main.cpp file here will be
    /*!   place the GameLoop and the game.
     *
     *
     *
     * @author Bergony Bandeira
     *
     * @date 10/12/2018
     */

    int cols{3};            //   Default Value.
    int rows{3};            //   Default Value.
    int width{100};         //   Default Value.
    int height{100};        //   Default Value.

    switch (argc)
    {
        case 1:
            std::cout << "wrong argument numbers\n";
            return -1;
        case 2:
            std::cout << "wrong argument numbers\n";
            return -1;
        case 3:
            std::cout << "wrong argument numbers\n";
            return -1;
        case 4:
            rows = atoi(argv[1]);
            cols = atoi(argv[2]);
            width = atoi(argv[3]);
            height = (cols * width) / rows;
            break;
        case 5:
            rows = atoi(argv[1]);
            cols = atoi(argv[2]);
            width = atoi(argv[3]);
            height = atoi(argv[4]);
            break;
        default:
            break;
    }

    std::cout << "============================ MAze Generator SOlve ================================" << "\n";
    std::cout << "Canvas Size " << width << " x " << height << "\n";
    std::cout << "Maze Size " << rows << " x " << cols << "\n";
    Game_Loop gl( rows, cols, width, height );

    gl.initializer();

    while(!gl.done())
    {
        gl.update();
    }

    return 0;

}

