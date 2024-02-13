#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <utility>

class matrix
{
    //   num_rows: integer, stores the number of rows
    //   num_cols: integer, stores the number of columns
    //   elements: integer pointer, pointing to a contiguous memory stores a row-major matrix.

    int num_rows;
    int num_cols;
    int *elements;

    // all functions below must be PUBLIC!
public:

    int get_num_rows() { return num_rows; }
    int get_num_cols() { return num_cols; }

    void set_elem(int i, int j, int value)
    {
        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols)
        {
            printf("invalid indices!\n");
        }
        else
        {
            elements[i * num_cols + j] = value;
        }
    }

    int get_elem(int i, int j)
    {
        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols)
        {
            printf("invalid indices!\n");
            return 'N';
        }
        else
        {
            return elements[i * num_cols + j];
        }
    }

    matrix(int nrow, int ncol)
    {
        if (nrow <= 0 || ncol <= 0)
        {
            printf("invalid dimensions!\n");
        }
        else
        {
            num_rows = nrow;
            num_cols = ncol;
            // printf("allocating memory for the matrix...\n");
            elements = (int *)malloc(num_rows * num_cols * sizeof(int));
        }
    }

    ~matrix()
    {
        // printf("freeing the matrix...\n");
        delete[] elements;
    }

    // print all elements in the matrix
    void print()
    {
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                printf("%d ", get_elem(i, j));
            }
            printf("\n");
        }
    }

};

class tictactoe{
    // Initialise a pointer to the board matrix
    // This memory does not need to be freed as the matrix deconstructor will do that for us.
    matrix *board;

    int isplayable(int i, int j) {
        if (board->get_elem(i, j) == 0) {
            return 1;
        }
        return 0;
    }

    int pieces_at_row(int i, int player){
        // Initialise counter:
        int count = 0;
        // iterate through rows counting friendly pieces
        for(int j = 0; j < 3; j++){
            if(board->get_elem(i, j) == player) count++;
        }
        return count;
    }
    int pieces_at_col(int j, int player){
        // Initialise counter:
        int count = 0;
        // iterate through columns counting friendly pieces
        for (int i = 0; i < 3; i++)
        {
            if (board->get_elem(i, j) == player)
            {
                count++;
            }
        }
        return count;
    }

    int pieces_at_diag(int player){
        // initialise counter
        int count = 0;
        // Count friendly pieces on the diagonal
        for (int i = 0; i < 3; i++)
        {
            if (board->get_elem(i, i) == player)
            {
                count++;
            }
        }
        return count;
    }
    int pieces_at_anti_diag(int player){
        // Initialise counter
        int count = 0;
        // Count friendly pieces on the anti-diagonal
        for (int i = 0; i < 3; i++)
        {
            if (board->get_elem(i, (2-i)) == player)
            {
                count++;
            }
        }
        return count;
    }

    // A function to turn Player 1 into "X" and turn Player 2 into "O".
    char getChar(int player)
    {
        if (player == 1)
        {
            return 'X';
        } else if (player == 2)
        {
            return 'O';
        } else
        {
            return '*';
        }
    }

    // evaluate the current move using greedy algorithm, 
    // the higher the score is, the better the move is
    int evaluate(int i, int j, int player){
        // who is player? who is opponent? 
        int opponent;
        if (player == 1)
        {
            opponent = 2;
        } else { opponent = 1;}

        // evaluate the situiation after the move
        // the higher the score is, the better the move is
        int f_ij = 0;

        f_ij += pieces_at_row(i, player);
        f_ij -= pieces_at_row(i, opponent);
        f_ij += pieces_at_col(j, player);
        f_ij -= pieces_at_col(j, opponent);

        if(i == j){
            f_ij += pieces_at_diag(player);
            f_ij -= pieces_at_diag(opponent);
        }
        if(i + j == 2){
            f_ij += pieces_at_anti_diag(player);
            f_ij -= pieces_at_anti_diag(opponent);
        }

        return f_ij;
    }


public:
    tictactoe(matrix initialBoard)
    {
        // Transfer the starting board matrix to the board variable held within the tictactoe class.
        board = new matrix(initialBoard.get_num_rows(), initialBoard.get_num_cols());
        for (int i = 0; i < initialBoard.get_num_rows(); i++)
        {
            for (int j = 0; j < initialBoard.get_num_cols(); j++)
            {
                board->set_elem(i, j, initialBoard.get_elem(i, j));
            }
        }
    }
    
    void play(int i, int j, int player) {
        if(isplayable(i, j)) {
            /// fill out the blanks
            board->set_elem(i, j, player);
        }
    }

    void play(int player){
        // Iterate through all free spaces on the board and evaluate moves at each square
        // play a move on the most optimal square according to the evaluate function

        // Store the best score and the square it was obtained in
        int bestEval = -__INT_MAX__;
        int bestRow = -1;
        int bestCol = -1;
        for (int i = 0; i < board->get_num_rows(); i++)
        {
            for (int j = 0; j < board->get_num_cols(); j++)
            {
                if (board->get_elem(i, j) == 0)
                {
                    int currentEval = evaluate(i, j, player);
                    if (currentEval > bestEval)
                    {
                        bestEval = currentEval;
                        bestRow = i;
                        bestCol = j;
                    }
                }
            }
        }
        // Play the best move that was found by the for loop above.
        play(bestRow, bestCol, player);
    }

    // Translate a matrix of 1s, 2s and 0s into Noughts and Crosses grid.
    void print()
    {
        for (int i = 0; i < board->get_num_rows(); i++)
        {
            for (int j = 0; j < board->get_num_cols(); j++)
            {
                printf("%c ", getChar(board->get_elem(i, j)));
            }
            printf("\n");
        }
    }
};

int main()
{
    // TODO initialise the board to 
    // X O * 
    // * * * 
    // * * *

    // NOTE: in this program I have changed the board to store the player number rather than the character
    //  as I found it easier to work with an integer array and then translate to actual noughts and crosses
    // later. I am also getting a "Double free of object error" which I have tried my best to fix but
    // I'm just not sure what is causing it. It isn't preventing the program from running so I have left it.
    matrix initialBoard(3,3);
    initialBoard.set_elem(0, 0, 1);
    initialBoard.set_elem(0, 1, 2);
    initialBoard.print();


    tictactoe game(initialBoard);
    printf("STARTING POSITION....\n");
    game.print();
    printf("\n");
    // and then call game.play('X') and game.play('O') until someone wins!
    printf("Player 1 Plays...\n");
    game.play(1);
    game.print();
    printf("\n");

    printf("Player 2 Plays...\n");
    game.play(2);
    game.print();
    printf("\n");

    printf("Player 1 Plays...\n");
    game.play(1);
    game.print();
    printf("\n");

    printf("Player 2 Plays...\n");
    game.play(2);
    game.print();
    printf("\n");
    return 0;
}