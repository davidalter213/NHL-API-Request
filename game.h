/* Author: David Alter
Description: Header file for NHL game class, holds a score of the home and away team
as well as the names of the teams in the game
Date: Feb 7th, 2023
*/
#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{
public:
    // constructor
    Game(std::string home_team, int home_score, std::string away_team, int away_score);
    // destructor
    ~Game();
    // getters and setters for all four variables
    std::string getHomeTeam() const;
    void setHomeTeam(const std::string &home_team);
    int getHomeScore() const;
    void setHomeScore(int home_score);
    std::string getAwayTeam() const;
    void setAwayTeam(const std::string &away_team);
    int getAwayScore() const;
    void setAwayScore(int away_score);

private:
    std::string ihome_team; // home team name
    int ihome_score;        // home score
    std::string iaway_team; // away team name
    int iaway_score;        // away score
};

#endif
