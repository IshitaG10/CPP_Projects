#include <iostream>
using namespace std;
int grid[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

//To check if the number is valid to be put in the place
bool isValid(int row,int col,int num){
    for(int i=0;i<9;i++){
        //check if the same number is present in column
        if(grid[i][col]==num)
         return false;
        
        //check if the same number is present in row
        if(grid[row][i]==num)
        return false; 

        //check if same number is present in 3*3 box
        if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==num)
        return false;
    }
    //if the same number is not present anywhere the number is valid
    return true;
}

//Sudoku solving function
bool sudokuSolver(){
    //traversing the sudoku to find empty place
    for(int i=0; i<9 ; i++){
      for(int j=0; j<9; j++){
        if(grid[i][j]==0){
            for(int num=1;num<=9;num++){
                if(isValid(i,j,num)){
                    
                grid[i][j] = num;
                
                //checking if the number leads to a solution for sudoku
                if(sudokuSolver()){
                    return true; //if the sudoku is solved
                }
                else //if sudoku is not solved with the number picked we change it back to empty space
                grid[i][j] = 0;
                }
            }
             //if no number is valid to fill the place we return false
            //this triggers the backtracking
            return false;
        }
      }
    }
   
    return true;
}



//Sudoku print function
void sudokuGrid(){ //print the sudoku grid after solve
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout << endl;
   }
}
int main(){
    sudokuGrid();
    if(sudokuSolver()){
    cout<<"After solving"<<endl;
    sudokuGrid();}
    else
    cout<<"No possible solution";
    return 0;
}