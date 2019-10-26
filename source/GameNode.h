// GameNode.h

#include "Node.h"
#include "Config.h"
#include "SimpleGame.h"


class GameNode : public Node 
{
    GameNode(SDL_Renderer* renderer_in, Node* parentNode_in): Node(renderer_in, parentNode_in)
    {
        SimpleGame* game = new SimpleGame;
        game -> addTextureToScreen(createImage(renderer_in, "brickBreakerNodeImages/brickBreakerScreen.png", true));

        Ball* ball = new Ball;
        ArcadeTecture* ballTecture = createImage(renderer_in, "brickBreakerNodeImages/ballTecture.png");

        ball->setGameObjectTexture(ballTexture);
        ball->setState(true);

        game->addEntity(ball);
        game->addMovingEntity(ball);
        game->setBall(Ball);

        game->setisNewGame(true);
        game->setGameState(true);

        this->addScreen(game);
        this->setCurrentGame(game);
    }
};