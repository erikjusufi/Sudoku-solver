#include<stdio.h>
#include<iostream>
#include<stdint.h>
#include<vector>
#include<list>
#include<queue>
#include <bits/stdc++.h> 
using namespace std;
typedef unsigned int uint;
using namespace std;
struct cvor{
	uint value;
	std::pair<uint, uint> tocka;
	std::pair<uint, uint> tocka_p;
};
class komparator
{
public:
  bool operator() (const cvor lhs, const cvor rhs) const
  {
    return (lhs.value > rhs.value);
  }
};
bool isSafe(int x, int y,int N, int M){
    return x >= 0 && x < N && y >= 0 && y < M;
}
uint solve(const uint N, const uint M, uint16_t *const problem, std::vector<std::pair<uint, uint> > &solution) {
	std::pair<uint, uint> tocka_poc;
	tocka_poc.first = 0;
	tocka_poc.second = 0;
	uint acc_cost[N][M];
	bool visited[N][M];
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            acc_cost[i][j] = 4294967295;
        }
    }
    vector<pair<uint,uint> > temp_solution;
   	priority_queue<cvor, vector<cvor>, komparator> pq;
    std::pair<uint, uint> tocka_kraj;
   	tocka_kraj.first = N-1;
   	tocka_kraj.second = M-1;
   	acc_cost[0][0] =*(problem);
   	cvor prvi_cvor;
   	temp_solution.push_back(tocka_poc);
	prvi_cvor.value =  *(problem);
	prvi_cvor.tocka = tocka_poc;
   	pq.push(prvi_cvor);
   	//cout<<"PRVO SAM OVDJE"<<endl;
   	while(!pq.empty()) {
   		cvor cvor = pq.top();
   		pq.pop();
   		int x = cvor.tocka.first;
   		int y = cvor.tocka.second;
   		//cout<<x<<" "<<y<<" "<<acc_cost[x][y]<<endl;
   		visited[x][y] = true;
   		std::pair<uint, uint> trenutna;
   		trenutna.first = x;
   		trenutna.second = y;
   		std::pair<uint, uint> dolje;
   		std::pair<uint, uint> desno;
   		desno.first = trenutna.first;
   		desno.second = trenutna.second+1;
   		dolje.first = trenutna.first+1;
   		dolje.second = trenutna.second;
   		temp_solution.push_back(tocka_poc);
   		//cout<<manhattan(dolje, konacna)<<endl;
   		//cout<<manhattan(desno, konacna)<<endl;
   		//cvorovi.tocka[0] = desno; 
   		//cvorovi.tocka[1] = dolje; 
   		//cvorovi.value[0] =  *(problem + desno.second%M + desno.first*(M)) + cost;
   		//cvorovi.value[1] = *(problem + dolje.second%M + dolje.first*(M)) + cost;		
   		if(isSafe(desno.first,desno.second,N,M) && acc_cost[desno.first][desno.second] == 4294967295) {
 			
   			acc_cost[desno.first][desno.second] = min(acc_cost[desno.first][desno.second], 
			   										acc_cost[x][y] + *(problem + desno.second%M + desno.first*(M)));
			
			pq.push({acc_cost[desno.first][desno.second], desno});
			//cout<<"+"<<endl;										
		   }
		if(isSafe(dolje.first,dolje.second,N,M) && acc_cost[dolje.first][dolje.second] == 4294967295) {
         
   		acc_cost[dolje.first][dolje.second] = min(acc_cost[dolje.first][dolje.second],acc_cost[x][y] + *(problem + dolje.second%M + dolje.first*(M)));
         
			pq.push({acc_cost[dolje.first][dolje.second], dolje});	
			//cout<<"+"<<endl;									
		   }
		
		}
		//cout<<"OVDJE SAM";
		//int uk_cijena = *problem;
	reverse(solution.begin(), solution.end());
	//cout<<acc_cost[N-1][M-1];
	return acc_cost[N-1][M-1];
	}







int main() { 

    //uint16_t polje[] = {1, 7, 9, 2, 8, 6, 6, 7, 1, 3, 2, 8};

       uint16_t polje[] = {100, 200, 1000, 0,
                        200, 100,  600, 0,
                        300, 1600, 100, 0};
    uint16_t *ptr;
    ptr = polje;
    std::vector<std::pair<unsigned int, unsigned int> > solution;

    uint16_t brCvijeca = solve(3, 4, ptr, solution);

    cout << "Kolicina cvijeca: " << brCvijeca;
    cout << "\n";

    for(int i=0; i<solution.size(); ++i){
        cout << "(" << solution[i].first << ", " << solution[i].second << ")" << endl;
    }
  
    return 0; 
}
