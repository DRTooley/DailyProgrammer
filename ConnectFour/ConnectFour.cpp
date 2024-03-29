#include <iostream>
#include <fstream>
#include <string>
#include <map>


//True if win condition is met
bool WinCondition(char ConnectFourBoard[][7], int MoveCount)
{
  char BoardPosition[7] = {'A','B','C','D','E','F','G'};
  for(int width=0; width<7;width++)
  {
    for(int height=0; height<6;height++)
    {
      if(ConnectFourBoard[height][width] != '\0')
      {
		  if(height <= 3)
	        {
				if(ConnectFourBoard[height+1][width] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height+2][width] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height+3][width] == ConnectFourBoard[height][width])
				{
					std::cout << ConnectFourBoard[height][width] << " won on move " <<
						MoveCount << " (with ";
					std::cout << BoardPosition[width] << height << ' ' << BoardPosition[width] << height+1
							  <<  ' ' << BoardPosition[width] << height+2 << ' ' << BoardPosition[width] 
							  << height+3;
					std::cout << " )" << std::endl;
					return true;
				}
			}
			if(width <= 4){
				if(ConnectFourBoard[height][width+1] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height][width+2] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height][width+3] == ConnectFourBoard[height][width])
				{
					std::cout << ConnectFourBoard[height][width] << " won on move " <<
						MoveCount << " (with ";
					std::cout << BoardPosition[width] << height << ' ' << BoardPosition[width+1] << height
							  <<  ' ' << BoardPosition[width+2] << height << ' ' << BoardPosition[width+3] 
							  << height;
					std::cout << " )" << std::endl;
					return true;
				}
			}
			if(height <= 3 && width <=4){
				if(ConnectFourBoard[height+1][width+1] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height+2][width+2] == ConnectFourBoard[height][width] &&
				   ConnectFourBoard[height+3][width+3] == ConnectFourBoard[height][width])
				{
					std::cout << ConnectFourBoard[height][width] << " won on move " <<
						MoveCount << " (with ";
					std::cout << BoardPosition[width] << height << ' ' << BoardPosition[width+1] <<
						height+1 << ' ' << BoardPosition[width+2] << height+2 << ' ' << 
						BoardPosition[width+3] << height+3;
					std::cout << " )" << std::endl;
					return true;
				}
			}
	  
      }
    }
  }
  
  return false;
}

void PrintBoard(char ConnectFourBoard[][7])
{
	std::cout << "    A   B   C   D   E   F   G" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	for(int i=5; i>=0; i--)
	{
		std::cout << i << " | ";
		for(int j=0;j<7;j++)
		{
			if(ConnectFourBoard[i][j] != '\0')
				std::cout << ConnectFourBoard[i][j] << " | "; 
			else
				std::cout << " " << " | "; 
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}


int main(int argc, char* argv[])
{
	int MoveCount = 0;
  char ConnectFourBoard[6][7] = {};
  int BoardHeight[7] = {};
  std::string line;
  std::ifstream ConnectFourMoves;
  ConnectFourMoves.open("ConnectFourMoves");
  if(ConnectFourMoves.is_open())
  {
    while(getline(ConnectFourMoves, line))
    {
      //Allow for comments in Moves file
      if(line[0]=='#')
      {
	continue;
      }
	  MoveCount++;
      char Player = '\0';
      for(int i=0; i<3; i+=2){
		  if(i==0)
		  {
			  Player = 'X';
		  }
		  else
		  {
			  Player='O';
		  }
		  switch (tolower(line[i]))
		  {
		  case 'a':
			  ConnectFourBoard[BoardHeight[0]][0] = Player;
			  BoardHeight[0]++;
			  break;
		  case 'b':
			  ConnectFourBoard[BoardHeight[1]][1] = Player;
			  BoardHeight[1]++;
			  break;
		  case 'c':
			  ConnectFourBoard[BoardHeight[2]][2] = Player;
			  BoardHeight[2]++;
			  break;
		  case 'd':
			  ConnectFourBoard[BoardHeight[3]][3] = Player;
			  BoardHeight[3]++;
			  break;
		  case 'e':
			  ConnectFourBoard[BoardHeight[4]][4] = Player;
			  BoardHeight[4]++;
			  break;
		  case 'f':
			  ConnectFourBoard[BoardHeight[5]][5] = Player;
			  BoardHeight[5]++;
			  break;
		  case 'g':
			  ConnectFourBoard[BoardHeight[6]][6] = Player;
			  BoardHeight[6]++;
			  break;
		  default:
			  std::cout << "Error dft occured! input: " << line << std::endl;
		  }
      }
	  PrintBoard(ConnectFourBoard);
      bool Winner = WinCondition(ConnectFourBoard, MoveCount);
      if(Winner)
      {
		  break;
      }
    }
  }  
  return 0;
}
