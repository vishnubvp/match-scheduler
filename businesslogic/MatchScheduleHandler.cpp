//
//  MatchScheduleHandler.cpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#include "MatchScheduleHandler.hpp"
#include "UtilityHandler.hpp"

TeamDetailsVPtr MatchScheduleHandler::ScheduleMatch(const std::vector<std::string> &teamDetails)
{
    int size = teamDetails.size();
    
    //Just Creating Array of teams
    TeamDetailsVPtr teamDetailsList;
    for (int i =0; i< size ; i++)
    {
        TeamDetailsPtr teamDetailsObj(new TeamDetails);
        teamDetailsObj->SetTeamName(teamDetails[i]);
        teamDetailsObj->SetIsHomeMatch(true);
        teamDetailsList.push_back(teamDetailsObj);
    }
    
    int count=1;
    for (int i =0; i< size ; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            teamDetailsList[i]->m_MatchIdVsOpponentsMap[count++] =teamDetails[j];
            teamDetailsList[j]->m_MatchIdVsOpponentsMap[count++] = teamDetails[i];
        }
    }
   
    return teamDetailsList;
}

void MatchScheduleHandler::DisplayScheduleDetails(const TeamDetailsVPtr &teamDetailsList)
{
    std::cout<<"Total Number of Matches Scheduled "<< GetNumberOfMatches(teamDetailsList.size())<<std::endl;
    std::cout<<"*********  Match Schedule  *********"<<std::endl;
    for(auto eachSchedule : teamDetailsList)
    {
        std::cout<< eachSchedule->GetTeamName() <<" 's Home Matches with Below Opponents" <<std::endl;
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<"MatchId"<<"   "<< "Opponent TeamName" <<std::endl;
        std::cout<<"---------------------------"<<std::endl;
        for(auto eachMatch : eachSchedule->m_MatchIdVsOpponentsMap)
        {
            std::cout<<"   "<<eachMatch.first <<"        "<<eachMatch.second<<std::endl;
        }
    }
}

int MatchScheduleHandler::GetNumberOfMatches(int n)
{
    int r = 2;// 2times the matches will happen between each teams
    //The Formula used here is n!/(n-r)!
    int div = n-r;
    int numOfMatches = Util::CalculateFactorial(n)/Util::CalculateFactorial(div);
    return numOfMatches;
}

bool MatchScheduleHandler::ValidateNumberOfTeams(int userInput)
{
    if(userInput %2 == 0)
        return true;
    return false;
}

std::vector<std::string> MatchScheduleHandler::GetTeamDetailsFromUser(int numOfTeams)
{
    TeamDetailsVPtr teamDetailsList;
    for(int i=0; i<numOfTeams ; i++ )
    {
        TeamDetailsPtr teamDetails(new TeamDetails);
        std::string teamName="";
        std::cin>>teamName;
        m_TeamNames.push_back(teamName);
    }
    return m_TeamNames;
}
