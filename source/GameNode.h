// GameNode 
 
// include the files we need
#include "Node.h"
#include "Config.h"
#include "SimpleGame.h" 
#include <stdio.h>
class GameNode : public Node // publicly inherits from Node
{
public:
    // Constructor                                            // initializer list
    GameNode(SDL_Renderer* renderer_in, Node* parentNode_in): Node(renderer_in, parentNode_in)
    {
        // create a gameScreen and add a texture to it
        SimpleGame* game = new SimpleGame; 
        game->addTextureToScreen(createImage(renderer_in,"brickBreakerNodeImages/brickBreakerScreen.png", true));
        
        // create an entity for the gameScreen
        Ball* ball = new Ball;

        // create an image for the entity
        ArcadeTexture* ballTexture = createImage(renderer_in, "brickBreakerNodeImages/ballTexture.png");
        ball->setGameObjectTexture(ballTexture);
        ball->setState(true);

        game->addEntity(ball); 
        game->addMovingEntity(ball);
        game->setBall(ball);

        game->setisNewGame(true);
        game->setGameState(true);

        this->addScreen(game);
        this->setCurrentScreen(game);
    }
};