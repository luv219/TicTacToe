# 🎮 Tic-Tac-Toe (C++) — Player vs Player | Player vs Computer

This is a console-based **Tic-Tac-Toe** game written in C++, featuring:

* **Player vs Player (PvP)** mode
* **Player vs Computer (PvC)** mode
* Score tracking, win/draw detection, and a user-friendly terminal interface

---

## 🧠 How to Play

* At startup, choose the game mode:

  1. Player vs Player
  2. Player vs Computer

* The board is laid out as follows:

```
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

* Players take turns placing their marks:

  * `Player 1` uses `X`
  * `Player 2` or the `Computer` uses `O`

* The first player to get **three in a row** wins (horizontally, vertically, or diagonally).

* You can play multiple rounds. Scores are displayed after each round and at the end.

---

## 🛠️ How to Compile and Run

```bash
g++ -o tictactoe tictactoe.cpp
./tictactoe
```

> ✅ Make sure `g++` or any C++ compiler is installed on your system.

---

## 🎯 Features

* 🔄 **Game Mode Selection**: Choose between PvP and PvC
* ✅ **Input Validation**: Prevents overwriting cells or entering invalid values
* 🤖 **Simple AI**: The computer randomly selects from available cells
* 📊 **Score Tracking**: Displays cumulative scores across rounds
* 🧼 **Clean UI**: Neatly rendered board and user-friendly prompts

---


