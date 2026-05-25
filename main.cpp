#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cctype>

using namespace std;
// Kích thước board game
#define H 25
#define W 20

// Ký tự hiển thị block và viền
const char BLOCK_CHAR = (char)219;
const char BORDER_CHAR = (char)178;

// Mảng lưu trạng thái board game
char board[H][W] = {};

// Vị trí hiện tại của block
int x, y, b;
int nextBlock;
int current_speed = 500;     // Tốc độ rơi hiện tại của block
bool wPressed = false;      // Biến chống spam xoay block
bool aPressed = false;
bool dPressed = false;
int score = 0;               // Điểm số người chơi
int total_lines = 0;        // Tổng số dòng đã xóa

//CLASS BLOCK
// Quản lý dữ liệu và thao tác của từng khối Tetris
class Block {
private:
    char shape[4][4];

public:
// Constructor mặc định
    Block() {
        clear();
    }

    Block(char input[4][4]) {
        setShape(input);
    }

// Xóa toàn bộ dữ liệu block
    void clear() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = ' ';
            }
        }
    }

// Gán hình dạng cho block
    void setShape(char input[4][4]) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = input[i][j];
            }
        }
    }

// Lấy giá trị tại vị trí (i, j) của block
    char getCell(int i, int j) {
        return shape[i][j];
    }

// Hàm xoay block theo chiều kim đồng hồ
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

// Khởi tạo 7 loại block Tetris
Block blocks[7];
void initBlocks() {
    char I[4][4] = {
        {' ', BLOCK_CHAR, ' ', ' '},
        {' ', BLOCK_CHAR, ' ', ' '},
        {' ', BLOCK_CHAR, ' ', ' '},
        {' ', BLOCK_CHAR, ' ', ' '}
    };

    char O[4][4] = {
        {' ', ' ', ' ', ' '},
        {' ', BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', ' ', ' ', ' '}
    };

    char T[4][4] = {
        {' ', ' ', ' ', ' '},
        {' ', BLOCK_CHAR, ' ', ' '},
        {BLOCK_CHAR, BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', ' ', ' ', ' '}
    };

    char S[4][4] = {
        {' ', ' ', ' ', ' '},
        {' ', BLOCK_CHAR, BLOCK_CHAR, ' '},
        {BLOCK_CHAR, BLOCK_CHAR, ' ', ' '},
        {' ', ' ', ' ', ' '}
    };

    char Z[4][4] = {
        {' ', ' ', ' ', ' '},
        {BLOCK_CHAR, BLOCK_CHAR, ' ', ' '},
        {' ', BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', ' ', ' ', ' '}
    };

    char J[4][4] = {
        {' ', ' ', ' ', ' '},
        {BLOCK_CHAR, ' ', ' ', ' '},
        {BLOCK_CHAR, BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', ' ', ' ', ' '}
    };

    char L[4][4] = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', BLOCK_CHAR, ' '},
        {BLOCK_CHAR, BLOCK_CHAR, BLOCK_CHAR, ' '},
        {' ', ' ', ' ', ' '}
    };

    blocks[0].setShape(I);
    blocks[1].setShape(O);
    blocks[2].setShape(T);
    blocks[3].setShape(S);
    blocks[4].setShape(Z);
    blocks[5].setShape(J);
    blocks[6].setShape(L);
}

// Kiểm tra block có thể di chuyển hay không
bool canMove(int dx, int dy){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b].getCell(i, j) != ' ') {
                int xt = x + j + dx;
                int yt = y + i + dy;         // Kiểm tra va chạm với tường hoặc block khác
                if (xt < 1 || xt >= W-1 || yt < 1 || yt >= H-1 ) return false;
                if (board[yt][xt] != ' ') return false;
            }
    return true;
}
// Ghi block hiện tại lên board
void block2Board(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b].getCell(i, j) != ' ')
            {
                int yi = y + i;
                int xj = x + j;
                if (yi >= 1 && yi < H-1 && xj >= 1 && xj < W-1)
                    board[yi][xj] = blocks[b].getCell(i, j);
            }
}

// Xóa block hiện tại khỏi board
void boardDelBlock(){
    for (int i = 0; i < 4; i++ )
        for (int j = 0; j < 4; j++ )
            if (blocks[b].getCell(i, j) != ' ')
            {
                int yi = y + i;
                int xj = x + j;
                if (yi >= 1 && yi < H-1 && xj >= 1 && xj < W-1)
                    board[yi][xj] = ' ';
            }
}

// Khởi tạo board game và viền
void initBoard(){
    for (int i = 0 ; i < H ; i++)
        for (int j = 0 ; j < W ; j++)
            if (i == 0 || i == H-1 || j ==0 || j == W-1) board[i][j] = BORDER_CHAR;
            else board[i][j] = ' ';
}
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
// Preview Next Block
void drawNextBlock() {

    gotoxy(W + 5, 2);
    cout << "NEXT BLOCK";

    for (int i = 0; i < 4; i++) {

        gotoxy(W + 5, 4 + i);

        for (int j = 0; j < 4; j++) {
            cout << blocks[nextBlock].getCell(i, j);
        }
    }
}


// Vẽ board game lên màn hình console
void draw(){
    // Di chuyển con trỏ console về góc trên bên trái
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    for (int i = 0 ; i < H ; i++, cout << endl)
        for (int j = 0 ; j < W ; j++)
            cout << board[i][j];

    gotoxy(0, H + 1);
    cout << "Score: " << score
     << " | Lines: " << total_lines
     << " | Speed: " << current_speed << "ms     ";

    gotoxy(0, H + 2);
    cout << "Controls: A/D move | W rotate | X down | Q quit   ";
    drawNextBlock();
}

// Hàm xóa dòng đầy và tăng tốc độ game
void removeLine() {
    int linesCleared = 0;

    for (int i = H - 2; i >= 1; i--) {
        bool fullLine = true;

        // Kiểm tra hàng có đầy không, bỏ qua viền trái/phải
        for (int j = 1; j < W - 1; j++) {
            if (board[i][j] == ' ') {
                fullLine = false;
                break;
            }
        }

        // Nếu hàng đầy thì xóa hàng
        if (fullLine) {
            linesCleared++;

            // Dồn các hàng phía trên xuống
            for (int row = i; row > 1; row--) {
                for (int col = 1; col < W - 1; col++) {
                    board[row][col] = board[row - 1][col];
                }
            }

            // Làm trống hàng trên cùng
            for (int col = 1; col < W - 1; col++) {
                board[1][col] = ' ';
            }

            // Kiểm tra lại chính hàng này sau khi dồn xuống
            i++;
        }
    }

    if (linesCleared > 0) {
        score += linesCleared * 100;
        total_lines += linesCleared;

        if (current_speed > 100) {
            current_speed -= 25 * linesCleared;
            if (current_speed < 100) current_speed = 100;
        }
    }
}

// Thêm tính năng endgame
void endGame() {
    system("cls"); // Xóa màn hình
    cout << "==============================" << endl;
    cout << "         GAME OVER            " << endl;
    cout << "==============================" << endl;
    cout << "Final Score : " << score << endl;
    cout << "Total Lines : " << total_lines << endl;
    cout << "Thanks for playing!" << endl;
    cout << "Press any key to exit..." << endl;
    getch(); // chờ người chơi nhấn phím
}
int main()
{
    srand(time(0));  // Khởi tạo ngẫu nhiên
    initBlocks();    // Khởi tạo các block Tetris
    // Ẩn con trỏ console
    x = W / 2 - 2; y = 1; b = rand()%7;
    nextBlock = rand() % 7;
    initBoard();

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    //GAME LOOP
    while (1){
        boardDelBlock();
        // Điều khiển block bằng bàn phím realtime
        // Di chuyển sang trái
        if (GetAsyncKeyState('A') & 0x8000) {
        
            // Chỉ di chuyển 1 lần mỗi lần nhấn
            if (!aPressed) {
        
                if (canMove(-1, 0))
                    x--;
        
                aPressed = true;
            }
        
        } else {
            aPressed = false;
        }
        
        // Di chuyển sang phải
        if (GetAsyncKeyState('D') & 0x8000) {
        
            // Chỉ di chuyển 1 lần mỗi lần nhấn
            if (!dPressed) {
        
                if (canMove(1, 0))
                    x++;
        
                dPressed = true;
            }
        
        } else {
            dPressed = false;
        }
        
        // Làm block rơi nhanh hơn
        if (GetAsyncKeyState('X') & 0x8000) {
            if (canMove(0, 1)) y++;
        }
        
        // Xoay block
        if (GetAsyncKeyState('W') & 0x8000) {
        
            // Chỉ xoay 1 lần cho mỗi lần nhấn
            if (!wPressed) {
        
                blocks[b].rotate();
        
                // Nếu xoay bị đụng tường hoặc block khác
                // thì xoay ngược lại để tránh lỗi
                if (!canMove(0, 0)) {
                    blocks[b].rotate();
                    blocks[b].rotate();
                    blocks[b].rotate();
                }
        
                wPressed = true;
            }
        
        } else {
            // Reset trạng thái khi nhả phím W
            wPressed = false;
        }
        
        // Thoát game
        if (GetAsyncKeyState('Q') & 0x8000) {
            break;
        }
        if (canMove(0,1)) y++;
        // Khi block không thể rơi tiếp
        else{
            block2Board();
            removeLine();
            x = W / 2 - 2;
            y = 1;
            b = nextBlock;
            nextBlock = rand() % 7;
            if (!canMove(0,0)) {
                endGame();
                break;
            }
        }
        block2Board();
        draw();
            Sleep(current_speed);
    }
    return 0;
}
