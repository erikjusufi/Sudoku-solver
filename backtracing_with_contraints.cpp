#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h>

// value field constisting of its coordiantes and value
struct cell {
	int value;
	int x;
   	int y;
};

// class for custom comparator for priority queue
class comparator {
public:
	bool operator() (const cell lhs, const cell rhs) const
	{
		return (lhs.value > rhs.value);
	}
};

class CP_sudoku {
public:
    struct SudokuField {
        int cell[9][9];
    };
    /**
	 * @brief Calculates the number of possible moves (valid numbers) for a specified cell in a Sudoku grid.
	 * 
	 * @param sudoku The 2D array representing the Sudoku grid.
	 * @param row The row index of the target cell.
	 * @param col The column index of the target cell.
	 * @return An integer representing the count of valid moves for the specified cell.
	 */
   	int possible_moves(int sudoku[9][9], int row, int col) {
      	int cnt = 0;
      	for(int num = 1; num <= 9; num++) {
         	bool isIt = true;
	      	for (int i = 0; i <9; i++) {
	      		// Check the entire column for conflicts with num
        		if(sudoku[i][col] == num) {
        			isIt = false;
        		}
        		// Check the entire row for conflicts with num
        		if (sudoku[row][i] == num) {
           			isIt=false;
        		}
         	}
         	// Check the 3x3 subgrid for conflicts with num
	      	for(int i = 0; i < 3; i++) {
	         	for(int j = 0; j< 3; j++) {
	            	if(sudoku[row+i - row%3][col + j-col%3] == num) {
	               		isIt=false;
	            	}
	         	}
	      	}
	        if(isIt){
	      		cnt++;
	        }
   		}
      	return cnt;
   	}
    /**
	 * @brief Checks if there are any empty cells in the Sudoku grid.
	 * 
	 * @param sudoku The 2D array representing the Sudoku grid.
	 * @param row Output parameter: The row index of the first empty cell found.
	 * @param col Output parameter: The column index of the first empty cell found.
	 * @return Returns false if an empty cell is found; true if all cells are filled.
	 */  
   	bool hasEmptyCells(int sudoku[9][9], int &row, int &col) {
      	for (row =0; row < 9; row++) {
         	for(col = 0; col <9; col++) {
            	if(sudoku[row][col] == -1) {
               		return false;
            	}
         	}
      	}
      	return true;
   }
   /**
	 * @brief Checks if placing a given number at a specified position in the Sudoku grid is valid.
	 * 
	 * @param sudoku The 2D array representing the Sudoku grid.
	 * @param row The row index of the target cell.
	 * @param col The column index of the target cell.
	 * @param num The number to be placed in the target cell.
	 * @return Returns false if placing 'num' at the specified position is invalid; true if it's a valid move.
	 */
   	bool is_valid_move(int sudoku[9][9], int row, int col,int num) {
   		// check if given cell isn't empty
      	if(sudoku[row][col] != -1){
         	return false;
      	}
      	
      	// check the entire column and row for conflicts with num
      	for (int i = 0; i <9; i++) {
	        if(sudoku[i][col] == num || sudoku[row][i] == num) {
	        	return false;
	        }
      	}
      	
		// check the 3x3 subgrid for conflicts with num
      	for(int i = 0; i < 3; i++) {
         	for(int j = 0; j< 3; j++) {
            	if(sudoku[row+i - row%3][col +j-col%3] == num) {
               		return false;
            	}
         	}
      	}
      	return true;
   	}
   	/**
	 * @brief Solves the Sudoku puzzle using a backtracking algorithm with prioritized empty cells.
	 * 
	 * @param init_values Reference to the 2D array representing the Sudoku grid.
	 * @return Returns true if a solution is found; false if no solution exists.
	 */
	bool sudokuSolve(int(&init_values)[9][9]) {
		// Create a priority queue to prioritize empty cell positions based on possible moves
  		std::priority_queue<cell, std::vector<cell>, comparator> pq;
  		// Fill the priority queue with empty cell positions and their corresponding possible moves
		for (int row =0; row < 9; row++) {
	     	for(int col = 0; col <9; col++) {
	           if(init_values[row][col]==-1) {
	              pq.push({possible_moves(init_values,row,col), row,col});
	           }
	        }
        } 
		int row,col;
      	if(!pq.empty()) {
      		cell cell = pq.top();
   			pq.pop();
      		row = cell.x;
      		col = cell.y;
      		//cout<<cell.value;
      	}
	    else{
	        return true;
	    }
      
      	//else {
        // if(hasEmptyCells(init_values,row,col)) {
       		//std::cout<<"+++"<<std::endl;
       		//return true;
       		//}
      	//}
       	for(int num =1; num <=9; num++) {
          	if(is_valid_move(init_values,row,col,num)) {
             	init_values[row][col] = num;
             	getIterations();
	            if(sudokuSolve(init_values)) {
	                return true;
             	}
             	// If no solution is found, backtrack by resetting the cell to -1
            	init_values[row][col] = -1;
          	}
       	}
       	return false;
	}
    // Solves the Sudoku puzzle and returns the solution      
    template <size_t rows, size_t cols>
    SudokuField *solve(int (&init_values)[rows][cols]){
    	// allocate memory for solution
	  	struct CP_sudoku::SudokuField* solution = (struct CP_sudoku::SudokuField*) malloc (sizeof(struct CP_sudoku::SudokuField));
		// Create a priority queue to prioritize empty cell positions based on possible moves
		std::priority_queue<cell, std::vector<cell>, comparator> pq;
		// Fill the priority queue with empty cell positions and their corresponding possible moves
	    for (int row = 0; row < 9; row++) {
	        for (int col = 0; col < 9; col++) {
	            if (init_values[row][col] == -1) {
	                int x = possible_moves(init_values, row, col);
	                pq.push({x, row, col});
	            }
	        }
	    }
              
       	if(sudokuSolve(init_values) == false) {
        	return NULL;
       	}
       	// Copy the solved Sudoku grid into the solution structure
       	for (int i=0 ; i<rows ; i++) {
            for (int j=0 ; j<cols ; j++) {
               (solution->cell)[i][j] = init_values[i][j];
            }
        }
       	return solution;
                
    }
    // Returns the number of iterations made during the solving process
    int getIterations(){
       return ++numOfIter;
    }
private:
   int numOfIter = 0;

};
int main() {
    int solution[9][9] = { { 9, 1, -1, 3, -1, -1, 7, -1, -1 },
                        { 7, -1, 8, -1, -1, -1, -1, -1, 9 },
                        { -1, 3, 2, 7, -1, -1, -1, -1, 1 },
                        { -1, -1, -1, 8, -1, -1, 2, 5, -1 },
                        { -1, -1, -1, -1, 2, -1, -1, -1, -1 },
                        { -1, 5, 4, -1, -1, 6, -1, -1, -1 },
                        { 4, -1, -1, -1, -1, 1, 8, 2, -1 },
                        { 1, -1, -1, -1, -1, -1, 6, -1, 5 },
                        { -1, -1, 6, -1, -1, 8, -1, 1, 7 } };
    CP_sudoku *solver = new CP_sudoku();
    CP_sudoku::SudokuField* sudoku_solution = solver->solve(solution);
    if (sudoku_solution != NULL) {
    	std::cout << "Final Solution:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << (sudoku_solution->cell)[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << "Backtrace calls: " << solver->getIterations() << "\n";
    } else {
        std::cout << "No solution exists.\n";
    }
    return 0;
}
