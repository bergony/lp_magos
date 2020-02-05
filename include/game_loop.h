#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include "../include/build.h"
#include "../include/render.h"
#include "../include/solve.h"

/// <b>Class</b> Game_loop <i>Class to control output. input and end of game.</i>
class Game_Loop
{
    private:
        
        // Maze setup.
        int rows{0};        
        int cols{0};
        int width{0};
        int height{0};
        
        //generator controll 
        int n_pictures{0};
        float percent{0};
        int trys{0};
        bool back_track{true};
        bool break_loop{false};
        bool printer{false};

        // folder strings
        std::string b_string = "Build/building_";
        std::string s_back_string = "Solve_Back/solving_";
        std::string s_hand_string = "Solve_Hand/solving_";
        std::string s_string;
        std::string output;

        //Objects to manipulate the maze
        Maze m;
        Build b;
        Solve s;

    public:
        //==================Special members========================
        /// ! Constructor Canvas
        /*!
        \param int r rows of maze
        \param int c colums of maze.
        \param int w Witdh of Image. 
        \param int h Height of Image .
        */
        Game_Loop( int r = 1, int c = 1, int w = 800, int h = 600):
            rows{r}, cols{c}, width{w}, height{h}
        {
            Maze m2(cols, rows);
            m = m2;
            Build b2( &m );
            Solve s2( &m );
            b = b2;
            s = s2;
        }

        /// ! Destructors Canvas
        ~Game_Loop(){}

        /// ! Method to check if the param are and set Maze m to status default.
        void initializer( void );

        /// ! Method to make one move on build or solve if is not done.)
        void update( void );

        /// ! Method to render the maze in a image PNG on folder.
        void render( void );

        /// ! Method to check if the maze is build, solve or did some error.
        /*!
          \return True if is Maze Is Build and Solve or Happends any error Otherwise False.
         */
        bool done( void );
};

#endif
