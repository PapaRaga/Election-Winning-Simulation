#include <iostream>
#include <random>
#include "header.h"
#include <iomanip>
#include <vector>
#include <cmath>

int main(int argle, char** argv){
     if (argle != 3){
		std::cerr << "The total amount of arguments should be 3. (program name and 2 parameters)" <<std::endl;
		return 1;
	}
    else{
        int n = std::atoi(argv[1]); //number of electoral divisions
        int m = std::atoi(argv[2]); //number of campaign days
        if((n < 1 || n > 10) || (m < 1 || m > 30)){
            std::cout<<"The arguments given are invalid. n should be within the range [1,10] while m is within [1,30]."<<std::endl;
            return 1;
        }
        //Initializing the campaign object
        Campaign campaign = nationInitialization(n,m);
        campaign.displayIssues();
        campaign.partyReport();
        campaign.nationReport();
        //Simulating the election campaign and running the random events
        campaign.campaignEvents();
        //Displaying results of the election day
        campaign.results();
    }
    return 0;
}
