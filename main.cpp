/* Author: David Alter
Description: Main function creates an API request to the NHL API to retrieve
a JSON object for all the games of the 2022-2023 season, it then creates a vector of
games and prints out the boxscores.
Date: Feb 7th, 2023
*/
#include "request.h"
#include "game.h"
#include <vector>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    Request request("https://statsapi.web.nhl.com/api/v1/schedule?startDate=2022-10-01&endDate=2023-02-07");
    if (request.Execute())
    {
        std::string response = request.Result();
        json j = json::parse(response);

        std::vector<Game> games;

        // get the information for each game
        for (auto &game : j["dates"][0]["games"])
        {
            std::string h_team = game["teams"]["home"]["team"]["name"].get<std::string>();
            int h_score = game["teams"]["home"]["score"].get<int>();
            std::string a_team = game["teams"]["away"]["team"]["name"].get<std::string>();
            int a_score = game["teams"]["away"]["score"].get<int>();
            games.emplace_back(h_team, h_score, a_team, a_score);
            std::cout << h_team << " vs " << a_team << " " << h_score << " - " << a_score << std::endl;
        }
    }

    return 0;
}