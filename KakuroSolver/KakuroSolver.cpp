#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*****************************************************************************************/
// I wish to understand the below code - I get to test my debug skills
// The below template was taken from Marius in:
// http://stackoverflow.com/questions/236129/split-a-string-in-c

template < class ContainerT >
void tokenize(const std::string& str, ContainerT& tokens,
              const std::string& delimiters = " ", bool trimEmpty = false)
{
   std::string::size_type pos, lastPos = 0;

   using value_type = typename ContainerT::value_type;
   using size_type  = typename ContainerT::size_type;

   while(true)
   {
      pos = str.find_first_of(delimiters, lastPos);
      if(pos == std::string::npos)
      {
         pos = str.length();

         if(pos != lastPos || !trimEmpty)
            tokens.push_back(value_type(str.data()+lastPos,
                  (size_type)pos-lastPos ));

         break;
      }
      else
      {
         if(pos != lastPos || !trimEmpty)
            tokens.push_back(value_type(str.data()+lastPos,
                  (size_type)pos-lastPos ));
      }

      lastPos = pos + 1;
   }
}
/****************************************************************************************/

bool SolutionCheck(){
	return false;
}


int main(){
	std::ifstream PuzzleFile("ExampleKakuroPuzzle");
	std::string PuzzleFileLine;
	std::vector <std::vector <std::string> > Tokens;
	if(PuzzleFile.is_open()){
		while(std::getline(PuzzleFile, PuzzleFileLine)){
			std::vector< std::string > TokenLine; 
			tokenize(PuzzleFileLine, TokenLine);
			Tokens.push_back(TokenLine);
		}

		

		
	}

	return 0;
}
