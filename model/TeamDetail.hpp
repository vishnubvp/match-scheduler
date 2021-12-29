//
//  TeamDetail.hpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#ifndef TeamDetail_hpp
#define TeamDetail_hpp

#include <iostream>
#include "TypeDefs.h"


FORWARD_DECLARE(TeamDetails);

class TeamDetails {
public:
    std::string m_TeamName;
    std::map<int , std::string>  m_MatchIdVsOpponentsMap; //Key is MatchId/Order and the value is Opponent Team Name
    bool m_IsHomeMatch;
    TeamDetails()
    {
        m_TeamName = "";
        m_MatchIdVsOpponentsMap.clear();
        m_IsHomeMatch = false;
    }
    
    void SetTeamName(std::string teamName);
    std::string GetTeamName();
    
    void SetIsHomeMatch(bool isHomeMatch);
    int GetIsHomeMatch();
    
};





#endif /* TeamDetail_hpp */
