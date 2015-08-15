#include <iostream>
#include <fstream>
#include <string>





int main(int argc, char* argv[]){
	if (argc < 1){
		std::cout << "The first argument must be a file containing the puzzle definition"
				  << std:: endl;
		return 1;
	}
	std::ifstream PuzzleFile(argv[0]);
	std::string PuzzleFileLine;
	if(PuzzleFile.is_open()){
		while(std::getline(PuzzleFile, PuzzleFileLine)){
			
		}
	}
	else{
		std::cout << "error: File '" << argv[0] << "'not found" << std::endl;
		return 1;
	}
	return 0;
}
