#include "../../unity/unity_fixture.h"
#include "../src/SDL_Snake.h"
#include "../include/SDL.h"

static SDL_Rect sdlRectT;
static SDL_Surface* pic = NULL;

static SDL_Surface* screen = NULL;
static SDL_Surface* background = NULL;
static SDL_Surface* playgound = NULL;
static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 

TEST_GROUP(SDL_Snake_Animation);


TEST_GROUP_RUNNER(SDL_Snake_Animation)
{
	RUN_TEST_CASE(SDL_Snake_Animation, SDL_Init);
	RUN_TEST_CASE(SDL_Snake_Animation, drawPicture);
	RUN_TEST_CASE(SDL_Snake_Animation, drawPlayground);
	//RUN_TEST_CASE(SDL_Snake_Animation, Animation);
}

TEST_SETUP(SDL_Snake_Animation)
{
  initGUI();
 
  screen = SDL_SetVideoMode(700, 700, 32, SDL_DOUBLEBUF); 
  background = SDL_LoadBMP("../resources/background.bmp");
  playgound = SDL_LoadBMP("../resources/background.bmp");
  snake = SDL_LoadBMP("../resources/snake.bmp");
  delSnake = SDL_LoadBMP("../resources/delSnake.bmp");
}

TEST_TEAR_DOWN(SDL_Snake_Animation)
{
  quit();
  SDL_FreeSurface(pic);
  
//   SDL_FreeSurface(background);
//   SDL_FreeSurface(snake);
//   SDL_FreeSurface(screen);	
//   SDL_FreeSurface(delSnake);
//   SDL_FreeSurface(playgound);
}

// Prvi test - SDL inicijalizacija
TEST(SDL_Snake_Animation, SDL_Init)
{
  TEST_ASSERT_EQUAL(0, initGUI());
}

// Drugi test - Crtanje slike
TEST(SDL_Snake_Animation, drawPicture)
{
  sdlRectT.x = 10;
  sdlRectT.y = 10;
  uint8_t a = 5;
  a = drawPic (sdlRectT, pic);
  TEST_ASSERT_EQUAL(0, a);
  
}

// Treci test - Animacija
TEST(SDL_Snake_Animation, drawPlayground)
{
  sdlRectT.x = INIT_OFFSET_PLAYGROUND_X;
  sdlRectT.y = INIT_OFFSET_PLAYGROUND_Y;
  drawPic (sdlRectT, background);
  
  sdlRectT = getPositionForLastPic();
  TEST_ASSERT_EQUAL(INIT_OFFSET_PLAYGROUND_X, sdlRectT.x);
  TEST_ASSERT_EQUAL(INIT_OFFSET_PLAYGROUND_Y, sdlRectT.y);
  SDL_Delay(5000);

}




