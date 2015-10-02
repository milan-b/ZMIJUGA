#include "../../unity/unity_fixture.h"
#include "../src/game.h"
#include "../../include/SDL.h"
#include "../../SDL/src/SDL_Snake.h"

static SDL_Rect sdlRectT;
static SDL_Surface* pic = NULL;


static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 

TEST_GROUP(game);


TEST_GROUP_RUNNER(game)
{
  RUN_TEST_CASE(game, Init);
  RUN_TEST_CASE(game, drawSnake);
}

TEST_SETUP(game)
{
  initGUI();
  //initGame() is called in Init test (first one)
}

TEST_TEAR_DOWN(game)
{
//   quit();
//   SDL_FreeSurface(pic);
  
//   SDL_FreeSurface(background);
//   SDL_FreeSurface(snake);
//   SDL_FreeSurface(screen);	
//   SDL_FreeSurface(delSnake);
//   SDL_FreeSurface(playgound);
}

// Prvi test
TEST(game, Init)
{
  TEST_ASSERT_EQUAL(0, initGame());
  SDL_Delay(500);
}
// Drugi test - draw snake
TEST(game, drawSnake)
{
  runGame();
  sdlRectT = getPositionForLastPic();
  TEST_ASSERT_EQUAL(PLAYGROUND_X / 2 + INIT_OFFSET_PLAYGROUND_X , sdlRectT.x);
  TEST_ASSERT_EQUAL(PLAYGROUND_Y / 2 + INIT_OFFSET_PLAYGROUND_Y , sdlRectT.y);
  SDL_Delay(500);
}