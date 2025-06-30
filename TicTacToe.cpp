#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

char board[9];
int player1Score = 0;
int player2Score = 0;
int computerScore = 0;
bool playGame = true;

enum Mode { PVP, PVC };
Mode gameMode;

const std::string WELCOME_MESSAGE = R"(
************************************************************
*                     Welcome to Tic-Tac-Toe!             *
*                    -------------------------            *
*                    Player vs Player / Computer          *
*                    -------------------------            *
*                    Positions:                           *
*                    1 | 2 | 3                            *
*                    ---------                            *
*                    4 | 5 | 6                            *
*                    ---------                            *
*                    7 | 8 | 9                            *
************************************************************
)";

void resetBoard() {
    for (int i = 0; i < 9; ++i)
        board[i] = '1' + i;
}

void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
        if (i < 6) std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

bool isWinner(char mark) {
    const int winCombos[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (auto& c : winCombos)
        if (board[c[0]] == mark && board[c[1]] == mark && board[c[2]] == mark)
            return true;
    return false;
}

bool isDraw() {
    for (char c : board)
        if (c != 'X' && c != 'O')
            return false;
    return true;
}

int getValidMove(const std::string& playerName) {
    int move;
    while (true) {
        std::cout << playerName << ", enter your move (1-9): ";
        std::cin >> move;
        if (std::cin.fail() || move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "❌ Invalid move. Try again.\n";
        } else {
            return move - 1;
        }
    }
}

void computerMove() {
    std::vector<int> choices;
    for (int i = 0; i < 9; ++i)
        if (board[i] != 'X' && board[i] != 'O')
            choices.push_back(i);

    if (!choices.empty()) {
        int choice = choices[rand() % choices.size()];
        board[choice] = 'O';
        std::cout << "💻 Computer chose position " << (choice + 1) << "\n";
    }
}

void playRound() {
    resetBoard();
    displayBoard();

    char current = 'X';
    std::string player1 = "Player 1 (X)";
    std::string player2 = gameMode == PVP ? "Player 2 (O)" : "Computer (O)";

    while (true) {
        if (current == 'X') {
            int move = getValidMove(player1);
            board[move] = 'X';
        } else {
            if (gameMode == PVP) {
                int move = getValidMove(player2);
                board[move] = 'O';
            } else {
                computerMove();
            }
        }

        displayBoard();

        if (isWinner(current)) {
            if (current == 'X') {
                std::cout << "🎉 " << player1 << " wins this round!\n";
                player1Score++;
            } else {
                std::cout << "🎉 " << player2 << " wins this round!\n";
                if (gameMode == PVP)
                    player2Score++;
                else
                    computerScore++;
            }
            break;
        }

        if (isDraw()) {
            std::cout << "🤝 It's a draw!\n";
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    std::cout << "🏅 Scoreboard:\n";
    std::cout << "Player 1: " << player1Score << "\n";
    if (gameMode == PVP)
        std::cout << "Player 2: " << player2Score << "\n";
    else
        std::cout << "Computer: " << computerScore << "\n";
}

void chooseGameMode() {
    int mode;
    std::cout << "Choose Game Mode:\n1. Player vs Player\n2. Player vs Computer\nChoice: ";
    std::cin >> mode;
    gameMode = (mode == 1) ? PVP : PVC;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << WELCOME_MESSAGE;
    std::cout << "Press Enter to start...";
    std::cin.ignore();
    std::cin.get();

    chooseGameMode();

    while (playGame) {
        playRound();

        char again;
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
        if (again == 'n' || again == 'N')
            playGame = false;
    }

    std::cout << "\nThanks for playing! Final scores:\n";
    std::cout << "Player 1: " << player1Score << "\n";
    if (gameMode == PVP)
        std::cout << "Player 2: " << player2Score << "\n";
    else
        std::cout << "Computer: " << computerScore << "\n";

    return 0;
}
