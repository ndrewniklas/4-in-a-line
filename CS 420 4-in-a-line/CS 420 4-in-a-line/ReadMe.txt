========================================================================
    CONSOLE APPLICATION : CS 420 4-in-a-line Project Overview
========================================================================

You have a 8x8 board, players take turns placing a piece on any grid. First player to get 4 in a line (either a row, or a column; diagonals are NOT counted) wins. The maximum amount of time allowed for generating the next move is 30 seconds. At the very beginning, your program should ask the user for the maximum amount time (in seconds) allowed for the computer to generate the answer and make sure that your search will stop when there's no time left. Your program should also ask the user to decide who is going to move first.

In order to make the process smooth, you are REQUIRED to use the following standard in the movement that your program will generate:

        1 2 3 4 5 6 7 8     Player vs. Opponent
      A - - - - - - - -        1. e5 d5
      B - - O - - - - -        2. e4 e3
      C - - O - - - - -        3. f4 d4
      D - X O O O X - -        4. e6 e7
      E - - O X X X O -        5. g4 h4
      F - - X X - - - -        6. d6 d3
      G - - - X - - - -        7. d2 c3
      H - - - O - - - -        8. f3 b3 wins

CS 420 4-in-a-line.cpp
    This is the main application source file.



/////////////////////////////////////////////////////////////////////////////
