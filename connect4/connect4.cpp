#include <vector>
#include <iostream>


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

void PlaceChip(int row)
{
    for (int i = board2d.size() - 1; i >= 0; i--)
    {
        if (board2d[i][row] == 0)
        {
            board2d[i][row] = player;
            break;
        }
    }
}

void SwapPlayer()
{
    if (player == 1) player = 2;
    else player = 1;
}

void DoTurn()
{
    int input;
    std::cout << "\n\n\n";
    std::cin >> input;
    PlaceChip(input);
    SwapPlayer();
}

void GameLoop()
{
    while (true)
    {
        DrawBoard();
        DoTurn();
    }
}

int main()
{
    GameLoop();
}