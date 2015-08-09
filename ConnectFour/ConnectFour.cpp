#include <iostream>
#include <fstream>
#include <string>
#include <array>

char WinCondition(char ConnectFourBoard[][7])
{
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
		  return ConnectFourBoard[height][width];
		}
	}
	if(width <= 4){
	  if(ConnectFourBoard[height][width+1] == ConnectFourBoard[height][width] &&
	     ConnectFourBoard[height][width+2] == ConnectFourBoard[height][width] &&
	     ConnectFourBoard[height][width+3] == ConnectFourBoard[height][width])
	    {
	      return ConnectFourBoard[height][width];
	    }
	}
	if(height <= 3 && width <=4){
	  if(ConnectFourBoard[height+1][width+1] == ConnectFourBoard[height][width] &&
	     ConnectFourBoard[height+2][width+2] == ConnectFourBoard[height][width] &&
	     ConnectFourBoard[height+3][width+3] == ConnectFourBoard[height][width])
	    {
	      return ConnectFourBoard[height][width];
	    }
	}
	  
      }
    }
  }
  
  return '\0';
}

int main(int argc, char* argv[])
{
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
      char Player = '\0';
      for(int i=0; i<3; i+=2){
	if(i==1)
	{
	  Player = 'X';
	}
	else
	{
	  Player='O';
	}
	switch (tolower(line[0]))
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
	}
      }
      char Winner = WinCondition(ConnectFourBoard);
      if(Winner != '\0')
      {
	std::cout << "The winner is " << Winner << "!" << std::endl;
	break;
      }
    }
  }  
  return 0;
}
