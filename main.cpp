//
//  main.cpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#include <iostream>
#include "TeamDetail.hpp"
#include "MatchScheduleHandler.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    MatchScheduleHandlerPtr matchScheduleHandlerObj(new MatchScheduleHandler);
    int numOfTeams;
    
    std::cout<<"Enter Number of Teams"<<std::endl;
    std::cin>>numOfTeams;
    
    if( numOfTeams == 0 || !matchScheduleHandlerObj->ValidateNumberOfTeams(numOfTeams))
    {
        cout<<"Received Invalid Number of Teams input! Provide Even number"<<endl;
        return 0;
    }
    
    std::cout<<"Enter Team Names"<<std::endl;
        
    std::vector<std::string> teamNames;
    teamNames = matchScheduleHandlerObj->GetTeamDetailsFromUser(numOfTeams);

    TeamDetailsVPtr teamDetailsList = matchScheduleHandlerObj->ScheduleMatch(teamNames);
    matchScheduleHandlerObj->DisplayScheduleDetails(teamDetailsList);
    return 0;
}
