#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;
#define H 20
#define W 15

const char BLOCK_CHAR = (char)219;
const char BORDER_CHAR = (char)178;

char board[H][W] = {};

int x, y, b;
int current_speed = 500;
class Block {
private:
    char shape[4][4];

public:
    Block() {
        clear();
    }

    Block(char input[4][4]) {
        setShape(input);
    }

    void clear() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = ' ';
            }
        }
    }

    void setShape(char input[4][4]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = input[i][j];
            }
        }
    }

    char getCell(int i, int j) {
        return shape[i][j];
    }

    void rotate() {
        char temp[4][4];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                temp[j][3 - i] = shape[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = temp[i][j];
            }
        }
    }
};
bool canMove(int dx, int dy){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ') {
                int xt = x + j + dx;
                int yt = y + i + dy;
                if (xt < 1 || xt >= W-1 || yt >= H-1 ) return false;
                if (board[yt][xt] != ' ') return false;
            }
    return true;
}
void block2Board(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ')
                board[y+i][x+j] = blocks[b][i][j];
}
void boardDelBlock(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b][i][j] != ' ')
                board[y+i][x+j] = ' ';
}
void initBoard(){
    for (int i = 0 ; i < H ; i++)
        for (int j = 0 ; j < W ; j++)
            if (i == 0 || i == H-1 || j ==0 || j == W-1) board[i][j] = BORDER_CHAR;
            else board[i][j] = ' ';
}
void draw(){
    //system("cls");
    COORD cursorPosition; cursorPosition.X = 0; cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    for (int i = 0 ; i < H ; i++, cout<<endl)
        for (int j = 0 ; j < W ; j++) cout << board[i][j];
}
void removeLine(){
    int i, j;
    for(i = H-2; i > 0; i--){
        for(j = 1; j < W - 1; j++)
            if (board[i][j] == ' ') break;
        if(j == W - 1){
            for(int ii = i; ii > 1; ii--)
                for(int jj = 1; jj < W - 1; jj++)
                board[ii][jj] = board[ii-1][jj];
            for(int jj = 1; jj < W - 1; jj++)
                board[1][jj] = ' ';

            if (current_speed > 100) current_speed -= 25;

            i++;
            draw();
            _sleep(200);
        }
    }
}

int main()
{
    srand(time(0));
    x = 5; y = 0; b = rand()%7;
    initBoard();

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    while (1){
        boardDelBlock();
        if (kbhit()){
            char c = getch();
            if (c == 'a' && canMove(-1,0)) x--;
            if (c == 'd' && canMove( 1,0)) x++;
            if (c == 'x' && canMove( 0,1)) y++;
            if (c == 'q') break;
        }
        if (canMove(0,1)) y++;
        else{
            block2Board();
            removeLine();
            x = 5; y = 0; b = rand()%7;
        }
        block2Board();
        draw();
        _sleep(current_speed);
    }
    return 0;
}
