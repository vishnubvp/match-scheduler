//
//  TeamDetail.cpp
//  MatchScheduler
//
//  Created by Vishnu Balasubramanian on 29/12/21.
//

#include "TeamDetail.hpp"


void TeamDetails::SetTeamName(std::string teamName)
{
    m_TeamName = teamName;
}
std::string TeamDetails::GetTeamName()
{
    return m_TeamName;
}

void TeamDetails::SetIsHomeMatch(bool isHomeMatch)
{
    m_IsHomeMatch = isHomeMatch;
}

int TeamDetails::GetIsHomeMatch()
{
    return m_IsHomeMatch;
}

