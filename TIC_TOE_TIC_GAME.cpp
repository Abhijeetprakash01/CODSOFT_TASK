
#include <iostream>
using namespace std;

class game
{
public:
  void gamestructure(int arr[3][3]);
  bool gamelogic(int arr[3][3], char currentPlayer);
  bool checkWin(int arr[3][3], char player);
};

void game::gamestructure(int arr[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    int j = 2;
    cout << "  " << static_cast<char>(arr[i][j--]) << "|"
         << " " << static_cast<char>(arr[i][j--]) << " "
         << "|" << static_cast<char>(arr[i][j--]) << endl;
    if (i == 2)
    {
      cout << "   "
           << "|"
           << "   "
           << "|"
           << "   ";
      break;
    }
    cout << "___"
         << "|"
         << "___"
         << "|"
         << "___" << endl;
  }
}

bool game::gamelogic(int arr[3][3], char currentPlayer)
{
  int pos;
  cout << "Player " << currentPlayer << ", select a position (1-9): ";
  cin >> pos;

  int row, col;

  // Convert position to row and column indices
  if (pos >= 1 && pos <= 9)
  {
    row = (pos - 1) / 3;
    col = (pos - 1) % 3;
  }
  else
  {
    cout << "Invalid position. Please choose a number between 1 and 9." << endl;
    return true;
  }

  // Check if the selected position is already occupied
  if (arr[row][col] == 'X' || arr[row][col] == 'O')
  {
    cout << "Position already occupied. Choose a different position." << endl;
    return false;
  }

  // Update the board with the player's move
  arr[row][col] = currentPlayer;

  // Display the updated board
  gamestructure(arr);

  // Check if the current player has won
  if (checkWin(arr, currentPlayer))
  {
    cout << "Player " << currentPlayer << " wins!" << endl;
    return true;
  }

  // Check for a draw (no more empty positions)
  bool isDraw = true;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] != 'X' && arr[i][j] != 'O')
      {
        isDraw = false;
        break;
      }
    }
  }

  if (isDraw)
  {
    cout << "It's a draw!" << endl;
    return true;
  }

  return false;
}

bool game::checkWin(int arr[3][3], char player)
{
  // Check rows, columns, and diagonals for a win
  for (int i = 0; i < 3; i++)
  {
    if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
    {
      return true; // Row win
    }
    if (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
    {
      return true; // Column win
    }
  }
  if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
  {
    return true; // Diagonal win (top-left to bottom-right)
  }
  if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
  {
    return true; // Diagonal win (top-right to bottom-left)
  }
  return false;
}

int main()
{
  game g1;
  int arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  g1.gamestructure(arr);

  char currentPlayer = 'X';
  bool gameOver = false;

  while (!gameOver)
  {
    gameOver = g1.gamelogic(arr, currentPlayer);
    if (currentPlayer == 'X')
    {
      currentPlayer = 'O';
    }
    else
    {
      currentPlayer = 'X';
    }
  }

  return 0;
}