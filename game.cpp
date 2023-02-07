/* Author: David Alter
Description: Implementation for NHL game class, holds a score of the home and away team
as well as the names of the teams in the game
Date: Feb 7th, 2023
*/

#include "game.h"
// constructor
Game::Game(std::string home_team, int home_score, std::string away_team, int away_score) : ihome_team(home_team), ihome_score(home_score), iaway_team(away_team), iaway_score(away_score) {}
// destructor
Game::~Game() {}

// getter method for home team name
std::string Game::getHomeTeam() const
{
    return ihome_team;
}

// setter method for home team name
void Game::setHomeTeam(const std::string &home_team)
{
    ihome_team = home_team;
}

// getter method for home score
int Game::getHomeScore() const
{
    return ihome_score;
}

// setter method for home score
void Game::setHomeScore(int home_score)
{
    ihome_score = home_score;
}

// getter method for away team name
std::string Game::getAwayTeam() const
{
    return iaway_team;
}

// setter method for away team name
void Game::setAwayTeam(const std::string &away_team)
{
    iaway_team = away_team;
}

// getter method for away score
int Game::getAwayScore() const
{
    return iaway_score;
}

// setter method for away score
void Game::setAwayScore(int away_score)
{
    iaway_score = away_score;
}
