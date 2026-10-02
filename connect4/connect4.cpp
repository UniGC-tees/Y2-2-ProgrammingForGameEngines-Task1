#include <vector>
#include <iostream>

struct pos
{
    int x;
    int y;
};

std::vector<std::vector<int>> board2d =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int player = 1;

void DrawLine(int row)
{
    std::cout << "|";
    for (int slot : board2d[row])
    {
        switch (slot)
        {
            case 0:
            {
                std::cout << "-";
                break;
            }
            case 1:
            {
                std::cout << "X";
                break;
            }
            case 2:
            {
                std::cout << "O";
                break;
            }
        }
        std::cout << "|";
    }
    std::cout << "\n";
}

void DrawNumbers()
{
    std::cout << "|";
    for (int i = 0; i < board2d.size() + 1; i++)
    {
        std::cout << i;
        std::cout << "|";
    }
    std::cout << "\n";
}

void DrawBoard()
{
    DrawNumbers();
    for (int i = 0; i < board2d.size(); i++)
    {
        DrawLine(i);
    }
    DrawNumbers();
}

pos PlaceChip(int row)
{
    for (int i = board2d.size() - 1; i >= 0; i--)
    {
        if (board2d[i][row] == 0)
        {
            board2d[i][row] = player;
            return pos{ row, i };
            break;
        }
    }
    return pos{ -1,-1 };
}

void SwapPlayer()
{
    if (player == 1) player = 2;
    else player = 1;
}

int Flip(int in)
{
    if (in == 1) return 2;
    if (in == 2) return 1;
}

bool CheckDraw()
{
    for (int i = 0; i < board2d.size() + 1; i++)
    {
        if (board2d[0][i] == 0) return false;
    }
    return true;
}

// true == win
bool CheckWin(pos lastChip)
{
 /*   int chipType = board2d[lastChip.y][lastChip.x];

    for (size_t i = 0; i < 4; i++)
    {
        if (board2d[lastChip.y - i][lastChip.x] != chipType) return false;
    }
    return true;*/

    return false;
}

// true == win
bool CheckBoard(pos lastChip)
{
    if (CheckDraw()) return true;
    if (CheckWin(lastChip)) return true;

    return false;
}

pos DoTurn()
{
    int input = -1;
    std::cout << "\n\n\n";
    std::cin >> input;
    pos lastChip = PlaceChip(input);
    SwapPlayer();
    return lastChip;
}

void GameLoop()
{
    pos lastChip;
    do
    {
        DrawBoard();
        lastChip = DoTurn();
    } while (CheckBoard(lastChip) == false);
}

int main()
{
    GameLoop();

    //game end

    DrawBoard();
    std::cout << "\n\n\n   !!!!!!!!\n game over!!!\n   !!!!!!!!\n\n\n ";
}