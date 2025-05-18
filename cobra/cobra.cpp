#define NOMINMAX
#define WIN32_LEAN_AND_MEAN    
#include <Windows.h>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
auto start = std::chrono::high_resolution_clock::now();

// wchar_t buf[2];
// buf[0] = static_cast<wchar_t>(i);
// buf[1] = L'\0';
// void ob(WCHAR* M, WCHAR* T){
//     MessageBoxW(0, M, T, MB_OK);
// }


//
int getInput(){
    if (GetAsyncKeyState(VK_UP)){
        return 0;
    }
    else if (GetAsyncKeyState(VK_DOWN)){
        return 1;
    }
    else if (GetAsyncKeyState(VK_LEFT)){
        return 2;
    }
    else if (GetAsyncKeyState(VK_RIGHT)){
        return 3;
    }
    else if (GetAsyncKeyState(VK_RETURN)){
        return 10;
    }
    else{
        return 4;
    }

}

std::vector<int> renderOptions(int height, int width, int velocity){
    int input = getInput();
    system("cls");
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(stdHandle, &ci);
    SetConsoleCursorPosition(stdHandle, {0, 0});

    std::cout<< "########################" << endl;
    std::cout<< "# OPCOES:              #" << endl;
    std::cout<< "#                      #" << endl;
    std::cout<< "# Tamanho X  :         #" << endl;
    std::cout<< "# Tamanho Y  :         #" << endl;
    std::cout<< "# Velocidade :         #" << endl;
    std::cout<< "#               Voltar #" << endl;
    std::cout<< "########################" << endl;
    std::cout<< "Cima/Baixo -> Selecionar" << endl;
    std::cout<< "Lados      -> Modificar " << endl;
    std::cout<< "Enter para selecionar.  " << endl;

    int selected = 4;

    while (true){
        Sleep(200);
        int input = getInput();
        if (input == 0 && selected < 4){
            selected++;
        }
        else if (input == 1 && selected > 1){
            selected--;
        }
        std::unordered_map <int, int> velos = {{50, 5}, {100, 4}, {150, 3}, {200, 2}, {250, 1}};

        SetConsoleCursorPosition(stdHandle, {1, 3});
        std::cout << " Tamanho X  :";
        SetConsoleCursorPosition(stdHandle, {1, 4});
        std::cout << " Tamanho Y  :";
        SetConsoleCursorPosition(stdHandle, {1, 5});
        std::cout << " Velocidade :";
        SetConsoleCursorPosition(stdHandle, {15, 6});
        std::cout << " Voltar ";
        SetConsoleCursorPosition(stdHandle, {15, 3});
        std::cout << to_string(width);
        SetConsoleCursorPosition(stdHandle, {15, 4});
        std::cout << to_string(height);
        SetConsoleCursorPosition(stdHandle, {15, 5});
        std::cout << to_string(velos[velocity]);

        if (selected == 4){
            SetConsoleCursorPosition(stdHandle, {1, 3});
            std::cout << "[Tamanho X] :";
            if (input == 3 && width < 70){
                width += 5;
            }
            else if (input == 2 && width > 10){
                width -= 5;
            }
        }
        if (selected == 3){
            SetConsoleCursorPosition(stdHandle, {1, 4});
            std::cout << "[Tamanho Y] :";
            if (input == 3 && height < 30){
                height += 5;
            }
            else if (input == 2 && height > 10){
                height -= 5;
            }
        }
        if (selected == 2){
            SetConsoleCursorPosition(stdHandle, {1, 5});
            std::cout << "[Velocidade]:";

            if (input == 2 && velocity < 250){
                velocity += 50;
            }
            else if (input == 3 && velocity > 50){
                velocity -= 50;
            }
        }
        if (selected == 1){
            SetConsoleCursorPosition(stdHandle, {15, 6});
            std::cout << "[Voltar]";
            if (input == 10){
                return {height, width, velocity};
            }
        }

    }
    
}

void renderMenu(){
    system("cls");
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(stdHandle, &ci);
    SetConsoleCursorPosition(stdHandle, {0, 0});

    std::cout<< "########################" << endl;
    std::cout<< "#                      #" << endl;
    std::cout<< "# Jogo da snake game   #" << endl;
    std::cout<< "#                      #" << endl;
    std::cout<< "#    JOGAR             #" << endl;
    std::cout<< "#            OPCOES    #" << endl;
    std::cout<< "#                      #" << endl;
    std::cout<< "########################" << endl;
    std::cout<< "Lados -> mover cursor;  " << endl;
    std::cout<< "Enter para selecionar.  " << endl;

    return;
}

// mode 0 = normal; 1 = W; 2 = L
void render(int height, int width, int mode = 0){  
    system("cls");
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(stdHandle, &ci);
    SetConsoleCursorPosition(stdHandle, {0, 0});
    
    if (mode == 1){
        std::cout<< "###################" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "#    Parabens!    #" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "#  Voce ganhao    #" << endl;
        std::cout<< "#     :heart_eyes:#" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "###################" << endl;
        std::cout<< "ENTER para continuar" << endl;
        return;
    }
    else if (mode == 2){
        std::cout<< "###################" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "#    Parabens!    #" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "#  Voce e um      #" << endl;
        std::cout<< "#        bosta    #" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "#                 #" << endl;
        std::cout<< "###################" << endl;
        std::cout<< "ENTER para continuar" << endl;
        return;
    }
    else{
        for (int y = 0; y<height; y++){
            for(int x =0; x<width; x++){
                std::cout << "..";
                
            }
            std::cout << endl ;
        }
    }
    
        
}

void plotPoint(int cx, int cy, bool mode, int colour = 2){
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(stdHandle, &ci);
    SetConsoleCursorPosition(stdHandle, {(short)(cx*2), (short)cy});
    if (mode){
        SetConsoleTextAttribute(stdHandle, colour);
        std::cout << "[]";
        SetConsoleTextAttribute(stdHandle, 15);
    }
    else{
        SetConsoleTextAttribute(stdHandle, 15);
        std::cout << "..";
    }
    SetConsoleCursorPosition(stdHandle, {0, 0});

}

std::vector<int> plotFood(std::vector<int> sx, std::vector<int> sy, int h, int w){
    int fx = 0;
    int fy = 0;

    while (true) {
        fx = std::rand() % w;
        fy = std::rand() % h;

        bool comidaCorpo = false;
        for (size_t i = 0; i < sx.size(); i++) {
            if (sx[i] == fx && sy[i] == fy) {
                comidaCorpo = true;
                break;
            }
        }

        if (!comidaCorpo)
            break; 
    }

    SetConsoleCursorPosition(stdHandle, {(short)(fx*2), (short)fy});
    SetConsoleTextAttribute(stdHandle, 4);
    std::cout << "<>";
    SetConsoleTextAttribute(stdHandle, 15);
    SetConsoleCursorPosition(stdHandle, {0,0});
    return {fx,fy};
}

int game(int height=10, int width=10, int velocity=150){
    bool gaming = true;
    int input = getInput();
    render(height, width);

    int vx = 1, vy = 0;                 // velocidade
    std::vector<int> sx = {3};         // posicoes cobra 
    std::vector<int> sy = {3};      
    int grow = 3; //quantas porrinhas a cobra cresce

    int size = 1; // tamanho total da cobra
    int winSize = (int)((height*width)*0.5); // tamanho para perder

    int fx = 0; //posicao comida
    int fy = 0;

    while (gaming){
        Sleep(velocity);
        input = getInput();
        if (input == 0){
            vx = 0;
            vy = -1;
        }
        else if (input == 1){
            vx = 0;
            vy = 1;
        }
        else if (input == 2){
            vx = -1;
            vy = 0;
        }
        else if (input == 3){
            vx = 1;
            vy = 0;
        }
        int pos = sx.size()-1; // pos cabeca

        if (sx[pos] > width-1 || sx[pos] < 0 || sy[pos] > height-1 || sy[pos] < 0){
            return (0);
            break;
        }

        if (sx[pos] == fx && sy[pos] == fy){
            grow++;
        }
        
        sx.push_back(sx[pos] += vx);
        sy.push_back(sy[pos] += vy);    

        for (int k = 0; k < sx.size()-1;k++){
            if(k != pos && sx[k] == sx[pos] && sy[k] == sy[pos]){
                return (0);
                break;
            }
        }

        plotPoint(sx[0], sy[0], false);
        if (grow == 0){
            sx.erase(sx.begin());
            sy.erase(sy.begin());
        }
        else if (grow > 0){
            if (grow == 1){
                std::vector<int> foodPos = plotFood(sx, sy, height, width);
                fx = foodPos[0];
                fy = foodPos[1];
            }
            size++;
            grow--;
        }
        pos = sx.size()-1;

        if (std::rand()%2 == 1){plotPoint(sx[pos], sy[pos], true, 2);}
        else {plotPoint(sx[pos], sy[pos], true, 9);}
        
        std::string progress = "";
        float percent = (size*100.0)/winSize;
        for (int i = 1; i < 11; i++){
            int current = i*10;
            if (current <= percent){
                progress += "#";
            }
            else{
                progress += "=";
            }
        }
        SetConsoleCursorPosition(stdHandle, {0, (short)height});
        std::cout << endl << "[ "<< progress << " ] " << (int)percent << "%" << endl;
        SetConsoleCursorPosition(stdHandle, {0, 0});

        if (size >= winSize){
            return (1);
            break;
        }

    }
}

int main(){
    std::srand(std::time(nullptr));
    
    int gaming = 3; // 1 = win | 2 = L | 3 = MENU
    int height = 10;
    int width = 10;
    int velocity = 150;

    Sleep(500);
    for (;;){
        int input = getInput();

        if (gaming == 1){
            render(10, 10, 1);
            Sleep(200);
            while (true){
                if(getInput() == 10){
                    gaming = 3;
                    break;
                }
            }
        }

        if (gaming == 2){
            render(10, 10, 2);
            Sleep(200);
            while (true){
                if(getInput() == 10){
                    gaming = 3;
                    break;
                }
            }
        }
        
        if (gaming == 3){
            Sleep(200);
            renderMenu();
            int selected = 2; // 0 = play 1 = options
            while (true){
                int input = getInput();
                
                if (input == 2){
                    selected = 0;
                    SetConsoleCursorPosition(stdHandle, {4, 4});
                    std::cout<< "[JOGAR]";
                    SetConsoleCursorPosition(stdHandle, {12, 5});
                    std::cout<< " OPCOES ";
                } 
                if (input == 3){
                    selected = 1;
                    SetConsoleCursorPosition(stdHandle, {4, 4});
                    std::cout<< " JOGAR ";
                    SetConsoleCursorPosition(stdHandle, {12, 5});
                    std::cout<< "[OPCOES]";
                }
                if (input == 10){
                    if (selected == 0){
                        int result = game(height, width, velocity);
                        if (result == 0){
                            gaming = 2;
                        }
                        else{
                            gaming = 1;
                        }
                        break;
                    }
                    else{
                        std::vector<int>newConfig = renderOptions(height, width, velocity);
                        height = newConfig[0];
                        width = newConfig[1];
                        velocity = newConfig[2];
                        selected = 2;
                        Sleep(50);
                        renderMenu();
                    }
                }
            }
        }
    }
    return 0;

}