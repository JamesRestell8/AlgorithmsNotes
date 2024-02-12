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
        free(elements);
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
    matrix board;

    int isplayable(int i, int j) {
        if (board.get_elem(i, j) == '*') {
            return 1;
        }
        return 0;
    }

    int pieces_at_row(int i, char player){
        int count = 0;
        for(int j = 0; j < 3; j++){
            if(board.get_elem(i, j) == player) count++;
        }
        return count;
    }
    int pieces_at_col(int j, char player){
        //TODO: Count player's pieces at j-th column
    }

    int pieces_at_diag(char player){
        //TODO: Count player's pieces at diagonal line
    }
    int pieces_at_anti_diag(char player){
       //TODO: Count player's pieces at anti-diagonal line
    }

    // evaluate the current move using greedy algorithm, 
    // the higher the score is, the better the move is
    int evaluate(int i, int j, char player){
        // who is player? who is opponent? 
        char opponent;
        if (player == 'X')
            opponent = 'O';
        else
            opponent = 'X';

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
        if(i + j == 4){
            f_ij += pieces_at_anti_diag(player);
            f_ij -= pieces_at_anti_diag(opponent);
        }

        return f_ij;
    }



public:
    tictactoe(): board(3,3) {
        //TODO: initialize the board with *
    }
    
    void play(int i, int j, char player) {
        if(isplayable(i, j)) {
            /// fill out the blanks
            //board.set_elem(__, __, __);
        }
    }

    void play(char player){
        // TODO: It play the next move for the "player",
        // play the move (i,j) is the maximizer of f(i,j)
    }

    // TODO add a print() method!

};

int main()
{
    //initialize a random tictactoe board
    tictactoe game;
    // TODO initialise the board to 
    // X O * 
    // * * * 
    // * * *
    // and then call game.play('X') and game.play('O') until someone wins!

}