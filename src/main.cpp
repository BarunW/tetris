#include <cstddef>
#include <cstdio>
#include <iostream>
#include<raylib.h>
#include <vector>

#include "block.h"

const int X = 600;
const int Y = 800;

const int GridLayoutX = 400;
const int GridLayoutY = 800;

typedef struct Grid{
    std::size_t numOfRows;
    std::size_t numOfCols;
    int cellSpace;
    std::vector<std::vector<int>> grid;   
    std::vector<Color> GetColors();
    std::vector<Color> colors;
    void DrawGrid();
    void Drawer(int x, int y, int w, int h, Color c);
    void RenderBlocks(int &PosX, int &PosY, Block block, int &rotation);
} Game;


void Game::Drawer(int x, int y, int width, int height, Color color){
    DrawRectangle(x, y, width, height, color);
}

std::vector<Color> Grid::GetColors(){
    Color darkGray = {0, 0, 54, 254};
    Color cyan = {21, 204, 209, 255};
    Color classic = {158, 173, 134, 1};
    return {darkGray, GREEN, RED, ORANGE, YELLOW, PURPLE, BLUE, cyan};
}

Grid NewGrid(size_t numOfRows, size_t numOfCols, int cellSpace){ 
    std::vector<std::vector<int>> grid(numOfRows, std::vector<int>(numOfCols));

    Grid g;
    g.numOfRows = numOfRows;
    g.numOfCols = numOfCols;
    g.cellSpace = cellSpace; 
    g.grid = grid; 
    g.colors = g.GetColors();
    return g;
}

void Game::DrawGrid(){
    int row, col; 
    for(row = 0; row < numOfRows; row++){
        for(col = 0; col < numOfCols; col++){
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSpace+1, row * cellSpace+1, cellSpace-1, cellSpace-1, colors[cellValue]);
        }
    }
}

void Game::RenderBlocks(int &PosX, int &PosY, Block block, int &rotation){
    std::vector<std::vector<int>> renderingBlock = block.blocks[rotation];
    printf("Pos X : %d , Pos Y: %d \n", PosX, PosY);
    for(size_t row = 0; row < renderingBlock.size(); row++){
        for(size_t col = 0; col < renderingBlock[0].size(); col++){                 
            if(renderingBlock[row][col] == 0 )
                DrawRectangle(PosY+col * cellSpace+1 , PosX+row * cellSpace+1 , 
                        cellSpace-1, cellSpace-1, YELLOW);  
        }
    }
}
 
 
int main(){
    InitWindow(X, Y, "TETRIS");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
        

    InitAudioDevice();
    Sound BgSoundWav = LoadSound("resources/bg.wav"); 

    Grid grid = NewGrid(20, 10, 40);
    SetTargetFPS(60);
    int renderPosX = 0;
    int renderPosY = 0;
    int rotation = 0;
    Block block = NewBlock_Hero();     
 
    while(!WindowShouldClose()){
        ClearBackground(BLACK);
        BeginDrawing();
        grid.DrawGrid();
        grid.RenderBlocks(renderPosX, renderPosY, block, rotation); 
        if(IsKeyPressed(KEY_P)) PlaySound(BgSoundWav);
        if ( renderPosX < GridLayoutY - block.blocks[rotation].size() * grid.cellSpace){
            renderPosX++;
            if(IsKeyPressed(KEY_DOWN)){
                renderPosX += grid.cellSpace;
                if (renderPosX > Y - 3 * grid.cellSpace) 
                    renderPosX = Y - 3 * grid.cellSpace; 
                
            }
            if(IsKeyPressed(KEY_RIGHT) && renderPosY < GridLayoutX - block.blocks[rotation].size() * grid.cellSpace){
                renderPosY += grid.cellSpace;
            }
            if(IsKeyPressed(KEY_LEFT) && renderPosY > 0){
                renderPosY -= grid.cellSpace;
            }

            if(IsKeyPressed(KEY_UP)){ 
                if (rotation <= block.NoOfRotation) rotation++; 
                if (rotation > block.NoOfRotation) rotation = 0; 
            }
        }
        EndDrawing();
    }
     
    CloseWindow(); 
    CloseAudioDevice();
    return 0;
}
