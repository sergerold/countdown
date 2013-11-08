#include "countdown.h"
#include <iostream>
#include <vector>

int main ()
{
	double values [6] = {75,50,2,3,8,7};
	int target = 812;
	int dev =5;

	std::vector <std::string> answers = countdown_solve (values,target, dev);

	
	for (int a=0;a < answers.size();a++)
		std::cout << answers[a]<<std::endl;
}
