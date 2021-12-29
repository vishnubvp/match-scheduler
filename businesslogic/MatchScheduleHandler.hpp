//
//  MatchScheduleHandler.hpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#ifndef MatchScheduleHandler_hpp
#define MatchScheduleHandler_hpp


#include <iostream>
#include "TypeDefs.h"
#include "TeamDetail.hpp"

FORWARD_DECLARE(TeamDetails)
FORWARD_DECLARE(MatchScheduleHandler)

class MatchScheduleHandler{
public:
    std::vector<std::string> m_TeamNames;
    TeamDetailsVPtr ScheduleMatch(const std::vector<std::string> &teamDetailsList);
    int GetNumberOfMatches(int n);
    void DisplayScheduleDetails(const TeamDetailsVPtr &teamDetailsList);
    bool ValidateNumberOfTeams(int userInput);
    std::vector<std::string> GetTeamDetailsFromUser(int numOfTeams);
};

#endif /* MatchScheduleHandler_hpp */
