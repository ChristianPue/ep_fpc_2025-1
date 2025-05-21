// EP_202121225_AraujoCanales_Christian_Pregunta_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Player {
    string name;
    int matches_played = 0;
    int matches_won = 0;
    int matches_lost = 0;
    int matches_tied = 0;
    int sets_won = 0;
    int points = 0;
};

struct Match {
    string player1;
    string player2;
    int sets_player1;
    int sets_player2;
};

int main() {
    string tournament_name;
    getline(cin, tournament_name);

    int n;
    cin >> n;

    if (n <= 0 || n >= 42 || n % 2 != 0) {
        cout << "Error: El numero de jugadores debe ser par y entre 1 y 41" << endl;
        return 1;
    }

    map<string, Player> players;

    for (int i = 0; i < n; i++) {
        string player_name;
        getline(cin, player_name);

        if (player_name.length() > 25) {
            cout << "Error: El nombre del jugador no debe superar los 25 caracteres" << endl;
            return 1;
        }

        Player player;
        player.name = player_name;
        players[player_name] = player;
    }

    int s;
    cin >> s;

    if (s <= 0 || s >= 20) {
        cout << "Error: El número de juegos debe estar entre 1 y 19" << endl;
        return 1;
    }

    vector<Match> matches;

    for (int i = 0; i < s; i++) {
        string line;
        getline(cin, line);

        size_t delimiterPos = line.find('@');
        string part1 = line.substr(0, delimiterPos);
        string part2 = line.substr(delimiterPos + 1);

        size_t dashPos1 = part1.find('-');
        size_t dashPos2 = part2.find('-');

        string player1 = part1.substr(0, dashPos1);
        int sets_player1 = stoi(part1.substr(dashPos1 + 1));

        string player2 = part2.substr(0, dashPos2);
        int sets_player2 = stoi(part2.substr(dashPos2 + 1));

        if (sets_player1 <= 0 || sets_player1 >= 20 || sets_player2 <= 0 || sets_player2 >= 20) {
            cout << "Error: Los sets deben estar entre 1 y 19" << endl;
            return 1;
        }

        // Crear nuevo partido
        Match match;
        match.player1 = player1;
        match.player2 = player2;
        match.sets_player1 = sets_player1;
        match.sets_player2 = sets_player2;
        matches.push_back(match);

        players[player1].matches_played++;
        players[player2].matches_played++;

        players[player1].sets_won += sets_player1;
        players[player2].sets_won += sets_player2;

        if (sets_player1 > sets_player2) {
            // Jugador 1 gana
            players[player1].matches_won++;
            players[player1].points += 2;
            players[player2].matches_lost++;
        }
        else if (sets_player1 < sets_player2) {
            // Jugador 2 gana
            players[player2].matches_won++;
            players[player2].points += 2;
            players[player1].matches_lost++;
        }
        else {
            // Empate
            players[player1].matches_tied++;
            players[player2].matches_tied++;
            players[player1].points += 1;
            players[player2].points += 1;
        }
    }

    // Análisis de resultados
    string most_matches_player;
    int max_matches = 0;

    string most_sets_player;
    int max_sets = 0;

    int tied_matches = 0;

    string most_wins_player;
    int max_wins = 0;

    string most_losses_player;
    int max_losses = 0;

    for (const auto& pair : players) {
        const Player& player = pair.second;

        if (player.matches_played > max_matches) {
            max_matches = player.matches_played;
            most_matches_player = player.name;
        }

        if (player.sets_won > max_sets) {
            max_sets = player.sets_won;
            most_sets_player = player.name;
        }

        if (player.matches_won > max_wins) {
            max_wins = player.matches_won;
            most_wins_player = player.name;
        }

        if (player.matches_lost > max_losses) {
            max_losses = player.matches_lost;
            most_losses_player = player.name;
        }

        tied_matches += player.matches_tied;
    }

    tied_matches /= 2;

    // Mostrar resultados
    cout << tournament_name << endl;
    cout << "1. " << most_matches_player << ", " << max_matches << " enfrentamientos" << endl;
    cout << "2. " << most_sets_player << ", " << max_sets << " sets" << endl;
    cout << "3. Empatados, " << tied_matches << " partido" << (tied_matches != 1 ? "s" : "") << endl;
    cout << "4. " << most_wins_player << ", " << max_wins << " enfrentamientos ganados, (" << players[most_wins_player].points << " puntos)" << endl;
    cout << "5. " << most_losses_player << ", " << max_losses << " enfrentamientos perdidos" << endl;

    return 0;
}