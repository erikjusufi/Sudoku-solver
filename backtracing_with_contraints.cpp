#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h> 
struct polje{
	int value;
	int x;
   int y;
};
class komparator
{
public:
  bool operator() (const polje lhs, const polje rhs) const
  {
    return (lhs.value > rhs.value);
  }
};
class CP_sudoku {
public:
    struct SudokuField {
        int field[9][9];
    };
   int potezi(int sudoku[9][9], int row, int col) {
      int cnt = 0;
      
      for(int num = 1; num <= 9; num++) {
         bool isIt = true;
      	for (int i = 0; i <9; i++) {
        		if(sudoku[i][col] == num) {
        			isIt = false;
        		}
        		if (sudoku[row][i] == num) {
           		isIt=false;
        		}
         }
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
      
   bool prazna_polja(int sudoku[9][9], int &row, int &col) {
      	for (row =0; row < 9; row++) {
         	for(col = 0; col <9; col++) {
            	if(sudoku[row][col] == -1) {
               		return false;
            	}
         	}
      	}
      	return true;
   }
   bool provjeri(int sudoku[9][9], int row, int col,int num) {
      	if(sudoku[row][col] != -1){
         	return false;
      	}
      	for (int i = 0; i <9; i++) {
        if(sudoku[i][col] == num || sudoku[row][i] == num) {
        	return false;
        }
      	}
      	for(int i = 0; i < 3; i++) {
         	for(int j = 0; j< 3; j++) {
            	if(sudoku[row+i - row%3][col +j-col%3] == num) {
               		return false;
            	}
         	}
      	}
      	return true;
   	}
	bool sudokuSolve(int(&init_values)[9][9]) {
      		std::priority_queue<polje, std::vector<polje>, komparator> pq;
			for (int row =0; row < 9; row++) {
         	for(int col = 0; col <9; col++) {
               if(init_values[row][col]==-1) {
                  pq.push({potezi(init_values,row,col), row,col});
               }
            }
         } 
		int row,col;
      if(!pq.empty()) {
      polje polje = pq.top();
   	pq.pop();
      row = polje.x;
      col = polje.y;
      //cout<<polje.value;
      }
      else{
         return true;
      }
      
      //else {
        // if(prazna_polja(init_values,row,col)) {
       		//std::cout<<"+++"<<std::endl;
       	//return true;
       //}
      //}
      
		
        //std::cout<<row<<" "<<col<<" "<<init_values[row][col]<<std::endl;
       for(int broj =1; broj <=9; broj++) {
       	//std::cout<<broj<<std::endl;
          if(provjeri(init_values,row,col,broj)) {
          	
             init_values[row][col] = broj;
             getIterations();
             //std::cout<<"-";
             if(sudokuSolve(init_values)) {
             	//std::cout<<"++++++"<<std::endl;
                return true;

             }
             init_values[row][col] = -1;
          }
       }
       return false;
	}
            
    template <size_t rows, size_t cols>
    SudokuField *solve(int (&init_values)[rows][cols]){
      	
      	struct CP_sudoku::SudokuField* rjesenje = (struct CP_sudoku::SudokuField*) malloc (sizeof(struct CP_sudoku::SudokuField));
 		std::priority_queue<polje, std::vector<polje>, komparator> pq;
			for (int row =0; row < 9; row++) {
         	for(int col = 0; col <9; col++) {
               if(init_values[row][col] == -1) {
                  int x = potezi(init_values,row,col);
                 
                     
                  	pq.push({x, row,col});


               }
            }
         } 
               
       if(sudokuSolve(init_values) == false) {
          return NULL;
       }
       for (int i=0 ; i<rows ; i++) {
            for (int j=0 ; j<cols ; j++) {
               (rjesenje->field)[i][j] = init_values[i][j];
            	//std::cout<<(rjesenje->field)[i][j]<<" ";
            }
            //std::cout<<std::endl;
         }
       //cout<<getIterations();
       return rjesenje;
                
    }
    int getIterations(){
       return ++numOfIter;
       //std::cout<<numOfIter;
    }
private:
   int numOfIter = 0;

};
int main() {
    int field[9][9] = { { 9, 1, -1, 3, -1, -1, 7, -1, -1 },
                        { 7, -1, 8, -1, -1, -1, -1, -1, 9 },
                        { -1, 3, 2, 7, -1, -1, -1, -1, 1 },
                        { -1, -1, -1, 8, -1, -1, 2, 5, -1 },
                        { -1, -1, -1, -1, 2, -1, -1, -1, -1 },
                        { -1, 5, 4, -1, -1, 6, -1, -1, -1 },
                        { 4, -1, -1, -1, -1, 1, 8, 2, -1 },
                        { 1, -1, -1, -1, -1, -1, 6, -1, 5 },
                        { -1, -1, 6, -1, -1, 8, -1, 1, 7 } };
    CP_sudoku *solver = new CP_sudoku();
    if (solver -> solve(field) != NULL) {
        std::cout << "\nBacktrace calls: " << solver -> getIterations() << "\n";
    }
    return 0;
}
