#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif


#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(20394); // ������ �ִ� ��� �Ҵ� ��ȣ�� �ߴ� ����

    {
        Game game;
        bool success = game.Initialize();
        if (success)
        {
            game.RunLoop();
        }
        game.Shutdown();
    }

    return 0;
}