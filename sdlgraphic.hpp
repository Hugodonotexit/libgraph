/*
MIT License

Copyright (c) 2024 Hugodonotexit

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

1.Attribution:
  All users of this Software must give appropriate credit to the original
creators. Such credit shall include, but not be limited to, the inclusion of the
following elements in any derived works, distributions, or publications: -The
name and version of the Software used. -A link to the original Software or the
original creator’s website (if applicable). -A clear statement that the work is
derived from or built with the Software. -The attribution must be placed in a
location that is reasonably conspicuous, ensuring that anyone using or
interacting with the derivative work is aware of the original creators'
contribution. 2.Commercial Use: Use of the Software for commercial purposes is
subject to prior approval by the original creators. Entities or individuals
wishing to use the Software for commercial gain must first seek and obtain
written permission from the copyright holders. The request for permission must
include: -A detailed description of the intended commercial use. -The expected
duration of such use. -Any potential modifications or derivatives to be created
from the Software. -Approval for commercial use is at the sole discretion of the
copyright holders and may be subject to specific terms and conditions as
stipulated at the time of approval. 3.Enforcement: Failure to comply with these
conditions will be considered a breach of the license and may result in
revocation of the rights granted under this License. The copyright holders
reserve the right to take any action deemed necessary to enforce compliance with
these terms, including legal proceedings.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef SDLGRAPHIC_H
#define SDLBGRAPH_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <omp.h>


#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#include <sstream>

#include "function.hpp"
#include "var.hpp"
namespace sgt {
class SDLG {
 private:
  std::vector<Vectorlf> points;
  bool isOpen;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event e;
  TTF_Font* font;
  std::vector<SDL_Texture*> textTextureX;
  std::vector<SDL_Surface*> textSurfaceX;
  std::vector<SDL_Texture*> textTextureY;
  std::vector<SDL_Surface*> textSurfaceY;
  std::vector<SDL_Rect> textRectX;
  std::vector<SDL_Rect> textRectY;
  std::vector<std::string> textNumX;
  std::vector<std::string> textNumY;
  SDL_Color textColor;
  Colour windowColour;
  std::vector<std::pair<Func, Colour>> funcs;
  std::vector<std::vector<LineSeg>> curves;
  std::vector<std::pair<LineSeg, Colour>> lines;
  std::vector<std::pair<LineSeg, Colour>> linesDraw;

  Vectorlf scale, centre;

  int winHeight, winWidth;

  // Private methods for internal functionalities
  void eventLoop();
  void drawGraphBackground();
  void drawLines();
  void drawCurve();
  void drawText();
  void updateLine();
  void updateCurve();
  void drawBackground();
  void updateText();

  Vectorlf transformPoint(Vectorlf p);
  std::string getDefaultFontPath();

 public:
  // Constructors
  SDLG();
  SDLG(Colour colour);
  SDLG(int height, int width);
  SDLG(int heigh, int width, Colour colour);

  // Public methods for external interface
  void setWinSize(int width, int height);
  void setWinwColour(Colour colour);
  void run();
  void setLine(Vectorlf, Vectorlf);
  void setLine(Vectorlf, Vectorlf, Colour colour);
  void deleteLine(int index);
  ~SDLG();

  void pushFunc(Func func);
  void pushFunc(Func func, Colour Colour);
  void removeFunc(int i);

  bool getStatus();
};

std::string SDLG::getDefaultFontPath() {
#ifdef _WIN32
    return "C:\\Windows\\Fonts\\arial.ttf"; // Adjust this path if needed
#elif __linux__
    return "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"; // Adjust this path if needed
#else
    return ""; // Unsupported platform
#endif
}

void SDLG::eventLoop() {
  // Handle events on queue
  while (SDL_PollEvent(&e) != 0) {
    // User requests quit
    switch (e.type) {
      case SDL_QUIT:
        isOpen = false;
        break;
      case SDL_MOUSEWHEEL:
            scale = scale + e.wheel.y;
            break;
      case SDL_KEYDOWN:
        switch (e.key.keysym.sym) {
          case SDLK_ESCAPE:
            isOpen = false;
            break; 
          case SDLK_LEFT:
            centre.x -= 1;
            break;
          case SDLK_RIGHT:
            centre.x += 1;
            break;
          case SDLK_UP:
            centre.y -= 1;
            break;
          case SDLK_DOWN:
            centre.y += 1;
            break;
        }
    }
  }
}

void SDLG::drawLines() {
  if (linesDraw.size() == 0) {
    return;
  }
  
  for (int i = 0; i < (int)linesDraw.size(); i++) {
    SDL_SetRenderDrawColor(renderer, linesDraw[i].second.r,
                           linesDraw[i].second.g, linesDraw[i].second.b,
                           linesDraw[i].second.t);

    SDL_RenderDrawLine(renderer, linesDraw[i].first.first.x,
                       linesDraw[i].first.first.y, linesDraw[i].first.second.x,
                       linesDraw[i].first.second.y);
  }
}
void SDLG::drawCurve() {
  if (funcs.size() == 0) {
    return;
  }
  
  for (int i = 0; i < (int)curves.size(); i++) {
    #pragma omp parallel for
    for (int j = 0; j < (int)curves[i].size(); j++) {
      SDL_SetRenderDrawColor(renderer, funcs[i].second.r, funcs[i].second.g,
                             funcs[i].second.b, funcs[i].second.t);

      SDL_RenderDrawLine(renderer, curves[i][j].first.x, curves[i][j].first.y,
                         curves[i][j].second.x, curves[i][j].second.y);
    }
  }
}

void SDLG::setWinSize(int width, int height) {
  SDL_SetWindowSize(window, width, height);
}

void SDLG::setWinwColour(Colour colour) { windowColour = colour; }

// Constructors implementation
SDLG::SDLG() : SDLG(600, 800, Colour::White()) {}
SDLG::SDLG(Colour colour) : SDLG(600, 800, colour) {}
SDLG::SDLG(int height, int width) : SDLG(height, width, Colour::White()) {}
SDLG::SDLG(int height, int width, Colour colour)
    : winHeight(height), winWidth(width) {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  scale.x = 10;
  scale.y = 10;
  centre.x = winWidth / 2;
  centre.y = winHeight / 2;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    return;
  }

  if (TTF_Init() == -1) {
        std::cerr << "TTF_Init: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return;
    }

  window = SDL_CreateWindow(
      "Simple Graphing Tool", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      this->winWidth, this->winHeight, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    TTF_Quit();
    SDL_Quit();
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return;
  }

  std::string fontPath = getDefaultFontPath();
    if (fontPath.empty()) {
        std::cerr << "No default font path found for this platform." << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return;
    }

  font = TTF_OpenFont(fontPath.c_str(), 24);
    if (font == nullptr) {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return;
    }

  int i = 0;
  do{
    SDL_Rect rect1;
    rect1.x = (winWidth/10) * i - 20;
    rect1.y = winHeight / 2 + 10;
    rect1.w = 40;
    rect1.h = 20;
    textRectX.push_back(rect1);
    double value = (-(double)winWidth / 2.0 + ((double)winWidth/10.0) * (double)i) / scale.x;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;

    textNumX.push_back(ss.str());
    textSurfaceX.push_back(TTF_RenderText_Solid(font, textNumX[i].c_str(), textColor));
    textTextureX.push_back(SDL_CreateTextureFromSurface(renderer, textSurfaceX[i]));
    if (textSurfaceX[i] == NULL || textTextureX[i] == NULL) {
    printf("TTF Error: %s\n", TTF_GetError()); 
    for (int j = 0; j < (int)textSurfaceX.size(); j++)
    {
      SDL_FreeSurface(textSurfaceX[j]);
    }   
    for (int j = 0; j < (int)textTextureX.size(); j++)
    {
      SDL_DestroyTexture(textTextureX[j]);
    } 
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return;
    }
    i++;
  } while (i < winWidth / (winWidth/10));

  i = 0;
  do{
    SDL_Rect rect1;
    rect1.x = winWidth / 2 + 10;
    rect1.y = (winHeight/10) * i - 10;
    rect1.w = 40;
    rect1.h = 20;
    textRectY.push_back(rect1);
    double value = ((double)winHeight / 2.0 - (double)i * ((double)winHeight/10.0)) / scale.y;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;

    textNumY.push_back(ss.str());
    textSurfaceY.push_back(TTF_RenderText_Solid(font, textNumY[i].c_str(), textColor));
    textTextureY.push_back(SDL_CreateTextureFromSurface(renderer, textSurfaceY[i]));
    if (textSurfaceY[i] == NULL || textTextureY[i] == NULL) {
    printf("TTF Error: %s\n", TTF_GetError()); 
    for (int j = 0; j < (int)textSurfaceY.size(); j++)
    {
      SDL_FreeSurface(textSurfaceY[j]);
    }   
    for (int j = 0; j < (int)textTextureY.size(); j++)
    {
      SDL_DestroyTexture(textTextureY[j]);
    } 
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return;
    }
    i++;
  } while (i < winHeight / (winHeight/10));

  setWinwColour(colour);
  isOpen = true;
}

void SDLG::run() {
    std::thread t1(std::bind(&SDLG::eventLoop, this));
    std::thread t2(std::bind(&SDLG::updateCurve, this));
    std::thread t3(std::bind(&SDLG::updateLine, this));
    updateText();

    t1.join();
    t2.join();
    t3.join();

    drawGraphBackground();
    drawBackground();
    drawLines();
    drawCurve();
    drawText();

    SDL_RenderPresent(renderer);
}

void SDLG::setLine(Vectorlf a, Vectorlf b) {
  Colour colour((rand() % 255), (rand() % 255), (rand() % 255), 255);
  setLine(a, b, colour);
}
void SDLG::setLine(Vectorlf a, Vectorlf b, Colour colour) {
  LineSeg lineSeg = std::make_pair(a, b);
  lines.push_back(std::make_pair(lineSeg, colour));
}

Vectorlf SDLG::transformPoint(Vectorlf p) {
  Vectorlf transformed;
  transformed.x = (p.x * scale.x + centre.x);
  transformed.y = (p.y * scale.y + centre.y);
  return transformed;
}

void SDLG::updateLine() {
  if (lines.size() == 0) {
    return;
  }
  linesDraw.erase(linesDraw.begin(), linesDraw.end());
  #pragma omp parallel for
  for (int i = 0; i < (int)lines.size(); i++) {
    auto p1 = std::async(std::launch::async, &SDLG::transformPoint, this,
                         lines[i].first.first);
    auto p2 = std::async(std::launch::async, &SDLG::transformPoint, this,
                         lines[i].first.second);
    linesDraw.push_back(
        std::make_pair(std::make_pair(p1.get(), p2.get()), lines[i].second));
  }
}

void SDLG::updateCurve() {
  if (funcs.size() == 0) {
    return;
  }

  curves.erase(curves.begin(), curves.end());
  
  for (int i = 0; i < (int)funcs.size(); i++) {
    std::vector<LineSeg> arc;
    for (double j = (-centre.x / scale.x); j < (((double)winWidth - centre.x) / scale.x);
         j += (1.0 / scale.x)) {
      double y1 = funcs[i].first.get_y(j);
      double y2 = funcs[i].first.get_y(j+(1.0 / scale.x));

      Vectorlf p1(j, y1);
      Vectorlf p2(j + (1.0 / scale.x), y2);

      auto _p1 =
          std::async(std::launch::async, &SDLG::transformPoint, this, p1);
      auto _p2 =
          std::async(std::launch::async, &SDLG::transformPoint, this, p2);
      arc.push_back(std::make_pair(_p1.get(), _p2.get()));
    }
    curves.push_back(arc);
  }
}

void SDLG::drawBackground() {
  SDL_GetWindowSize(window, &winWidth, &winHeight);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);

  SDL_RenderDrawLine(renderer, -5, centre.y, winWidth + 5, centre.y);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);

  SDL_RenderDrawLine(renderer, centre.x, -5, centre.x, winHeight + 5);
}

void SDLG::drawGraphBackground() {
  SDL_SetRenderDrawColor(renderer, windowColour.r, windowColour.g,
                         windowColour.b, windowColour.t);
  SDL_RenderClear(renderer);
}

void SDLG::updateText() {
  for (size_t i = 0; i < textRectY.size(); i++)
  {
    SDL_FreeSurface(textSurfaceY[i]);
    SDL_DestroyTexture(textTextureY[i]);
    textRectY[i].x = centre.x + 10;
    textRectY[i].y = (winHeight/10) * i - 10;

    double value = (centre.y - (double)i * ((double)winHeight/10.0)) / scale.y;
    
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    textNumY[i] = ss.str();
    textSurfaceY[i] = TTF_RenderText_Solid(font, textNumY[i].c_str(), textColor);
    textTextureY[i] = SDL_CreateTextureFromSurface(renderer, textSurfaceY[i]);

  }

  for (size_t i = 0; i < textRectX.size(); i++)
  {
    SDL_FreeSurface(textSurfaceX[i]);
    SDL_DestroyTexture(textTextureX[i]);
    textRectX[i].x = (winWidth/10) * i - 20;
    textRectX[i].y = centre.y + 10;

    double value = (-centre.x + ((double)winWidth/10.0) * (double)i) / scale.x;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    textNumX[i] = ss.str();
    
    textSurfaceX[i] = TTF_RenderText_Solid(font, textNumX[i].c_str(), textColor);
    textTextureX[i] = SDL_CreateTextureFromSurface(renderer, textSurfaceX[i]);
  }
}

void SDLG::drawText() {
  for (size_t i = 0; i < textRectX.size(); i++)
  {
    SDL_RenderCopy(renderer, textTextureX[i], NULL, &textRectX[i]);
  }
  for (size_t i = 0; i < textRectY.size(); i++)
  {
    SDL_RenderCopy(renderer, textTextureY[i], NULL, &textRectY[i]);
  }
}

void SDLG::deleteLine(int index) { lines.erase(lines.begin() + index); }

SDLG::~SDLG() {
  for (size_t i = 0; i < textTextureX.size(); i++)
  {
    SDL_DestroyTexture(textTextureX[i]);
  }
  for (size_t i = 0; i < textSurfaceX.size(); i++)
  {
    SDL_FreeSurface(textSurfaceX[i]);
  }
  for (size_t i = 0; i < textTextureY.size(); i++)
  {
    SDL_DestroyTexture(textTextureY[i]);
  }
  for (size_t i = 0; i < textSurfaceY.size(); i++)
  {
    SDL_FreeSurface(textSurfaceY[i]);
  }
  
  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();

}

void SDLG::pushFunc(Func func, Colour colour) {
  funcs.push_back(std::make_pair(func, colour));
}
void SDLG::pushFunc(Func func) {
  Colour colour((rand() % 255), (rand() % 255), (rand() % 255), 255);
  pushFunc(func, colour);
}
void SDLG::removeFunc(int i) { 
  funcs.erase(funcs.begin() + i); 
  curves.erase(curves.begin() + i);
  }
bool SDLG::getStatus() {return isOpen;}
}  // namespace sgt
#endif