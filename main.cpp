#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>

std::ostringstream convert;

enum ops
{
    add ,
    subtract ,
    multiply ,
    divide

};

std::vector < std::vector<int> > generateops()
{

int count =0;
    std::vector <int> ops (5) ;

    std::vector <std::vector <int> > arr;

    for (int a=0; a < 4;a++)
    {
         for (int b=0; b < 4;b++)
        {

             for (int c=0; c < 4;c++)
            {
                 for (int d=0; d < 4;d++)
                {
                     for (int e=0; e < 4;e++)
                    {
                            ops [0] = a, ops[1] =b,ops[2] =c,ops[3]=d,ops[4]=e;
                            //print
                            arr.push_back(ops);
                    }

                }
            }

        }

    }

return arr;
}

bool is_integer(float k)
{
  return std::floor(k) == k;
}

int main()
{
    double myints[6] = {25,50,75,100,3,6};

    int target =952 ;
    int best;
    std::vector <std::vector<int> > opslist = generateops();
    std::vector <std::string> solutions;

  std::sort (myints,myints+sizeof(myints)/sizeof(double));

  do {//every perm of numbers

    for (int opssize = 0;opssize <opslist.size() ;opssize++)  //every combination of ops
    {
        double temp = myints[0];

        for (int calc=1;calc<6;calc++) //perform operation
        {
            if (opslist[opssize][calc-1] == add)
                temp = temp + myints[calc];

            if (opslist[opssize][calc-1] == subtract)
                temp = temp - myints[calc];

            if (opslist[opssize][calc-1] == multiply)
                temp = temp * myints[calc];

            if (opslist[opssize][calc-1] == divide)
                temp = temp / myints[calc];


             if (!is_integer(temp) || temp<1)      //not valid then move to next possibility
                break;


            if ( temp == target )   //check target matched and positive int
            {

                std::string temp;
                convert.str("");
                convert << myints[0];
                temp+= convert.str();

                convert.str("");
                convert.clear();

                for (int a=1; a <= calc; a++ )
                {


                    if (opslist[opssize][a -1 ] == add)
                        temp += " + ";

                    if (opslist[opssize][a - 1] == subtract)
                        temp += " - ";

                    if (opslist[opssize][a - 1 ] == multiply)
                        temp += " * ";

                    if (opslist[opssize][a - 1] == divide)
                        temp += " / ";

                    convert << myints[a];
                    temp += convert.str();
                    convert.str("");

                }
                solutions.push_back(temp);

            }
        }

    }

  } while ( std::next_permutation(myints,myints+sizeof(myints)/sizeof(double)) );

    //remove duplicates
    std::sort(solutions.begin(), solutions.end());
    solutions.erase(std::unique(solutions.begin(), solutions.end()), solutions.end());

    //print
    for (int a=0;a<solutions.size();a++)
        std::cout << solutions[a]<< std::endl;

    std::cout << solutions.size();
    return 0;
}
